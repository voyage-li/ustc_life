drop procedure if exists updateReaderID;
delimiter //
create procedure updateReaderID(in oldid char(8), in newid char(8), out ret int)
begin 
    declare tmp char(8);
    set ret = 0;
    start transaction;
    set FOREIGN_KEY_CHECKS = 0;
    select ID into tmp from `Reader` where ID = oldid;
    if tmp is not null then
        update `Reader` set ID = newid where ID = oldid;
        update `Borrow` set readerID = newid where readerID = oldid;
        set FOREIGN_KEY_CHECKS = 1;
        select 'Success!';
        commit;
    else
        set ret = -1;
        select 'Fail!';
        rollback;
    end if;
end//
delimiter ;
