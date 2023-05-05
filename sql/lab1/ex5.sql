-- Active: 1682256568013@@127.0.0.1@3306@lab1
drop procedure if exists returnbook;
delimiter //
create procedure returnbook(in rdid char(8), in boid char(8), out ret int)
begin
    set ret = 0;
    start transaction;

    if not exists(select * from `Borrow` where boid = bookID and rdid = readerID and returnDate is null) then
        set ret = -1;
        select 'Error!';
        rollback;

    else
        update `Book` set status = IF(exists(select * from Reserve where bookID = boid),2,0) where ID = boid;
        update `Borrow` set returnDate = Date(now()) where bookID = boid and readerID = rdid and returnDate is null;
        select 'Success';
        commit;
    end if;
    


end//
delimiter ;