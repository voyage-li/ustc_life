-- Active: 1682256568013@@127.0.0.1@3306@lab1
drop procedure if exists borrowBook;
delimiter //
create procedure borrowBook(in rdid char(8), in boid char(8), out ret int)
label:begin
    declare tmp date;
    declare respeople char(8);
    declare books int;
    set ret = 0;
    start transaction;

    if not exists(select * from Reader where ID = rdid)
    or not exists(select * from Book where ID = boid) then
        set ret = -1;
        select 'not exists reader or book!'
        rollback;
        leave label;
    end if;

    select borrowDate into tmp from `Reader`,`Borrow` 
    where `Reader`.ID = `Borrow`.readerID and `Reader`.ID = rdid 
            and `Borrow`.borrowDate = Date(now());
    if tmp is not null then
        set ret = -1;
        select 'borrow too many times one day!'
        rollback;
        leave label;
    end if;
    
    if exists(select * from `Reserve` where bookID = boid and readerID != rdid) and
    not exists(select * from `Reserve` where bookID = boid and readerID = rdid) then
        set ret = -1;
        select 'have not reserve!'
        rollback;
        leave label;
    end if;

    select count(*) into books from `Borrow`
    where readerID = rdid and returnDate is null group by readerID;
    if books >= 3 then
        set ret = -1;
        select 'borrow too many books!'
        rollback;
        leave label;
    end if;

    select readerID into respeople from `Reserve` where bookID = boid and readerID = rdid;    
    if respeople is null then
        insert into Borrow value(boid, rdid, Date(now()), NULL);
        update `Book` set status = 1, borrowTimes = borrowTimes + 1 where ID = boid;
        select 'Success!'; 
    else
        insert into Borrow value(boid, rdid, Date(now()), NULL);
        update `Book` set status = 1, borrowTimes = borrowTimes + 1 where ID = boid;
        delete from `Reserve` where bookID = boid and readerID = rdid; 
        select 'Success!';        
    end if;  
    commit;
end//
delimiter ;