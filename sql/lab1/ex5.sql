drop procedure if exists returnbook;
delimiter //
create procedure returnbook(in rdid char(8), in boid char(8), out ret int)
begin
    declare tmp char(8);
    set ret = 0;
    start transaction;

    select bookID into tmp from `Borrow` where boid = bookID and rdid = readerID and returnDate is null;
    if tmp is null then
        set ret = -1;
        select 'Error!';
        rollback;

    else
        update `Book` set status = 0 where ID = boid;
        update `Borrow` set returnDate = Date(now()) where bookID = boid and readerID = rdid;
        select 'Success';
        commit;
    end if;
    


end//
delimiter ;