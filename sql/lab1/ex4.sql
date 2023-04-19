drop procedure if exists borrowBook;
delimiter //
create procedure borrowBook(in rdid char(8), in boid char(8), out ret int)
begin
    declare tmp date;
    declare respeople char(8);
    declare books int;
    set ret = 0;
    start transaction;

    select borrowDate into tmp from `Reader`,`Borrow` 
    where `Reader`.ID = `Borrow`.readerID and `Reader`.ID = rdid 
            and `Borrow`.borrowDate = Date(now());
    if tmp is not null then
        set ret = -1;
        rollback;
    end if;
    

    select readerID into respeople from `Reserve` where bookID = boid and readerID != rdid;
    if respeople is not null then
        set ret = -1;
        rollback;
    end if;

    select count(*) into books from `Borrow`
    where readerID = rdid and returnDate is null group by readerID;
    if books >= 3 then
        set ret = -1;
        rollback;
    end if;

    select readerID into respeople from `Reserve` where bookID = boid and readerID = rdid;    
    if respeople is null then
        set ret = -1;
        rollback;
    end if;

    insert into Borrow value(boid, rdid, Date(now()), NULL);
    update `Book` set status = 1, borrowTimes = borrowTimes + 1 where ID = boid;
    delete from `Reserve` where bookID = boid and readerID = rdid;   
    commit;
end//
delimiter ;