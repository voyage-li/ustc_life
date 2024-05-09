-- Active: 1682256568013@@127.0.0.1@3306@lab1
drop procedure if exists updateReaderID;
delimiter //
create procedure updateReaderID(in oldid char(8), in newid char(8), out ret int)
begin 
    set ret = 0;
    start transaction;
    if exists(select * from `Reader` where ID = oldid) 
    and not exists(select * from Reader where ID = newid) then
        set FOREIGN_KEY_CHECKS = 0;
        update `Reader` set ID = newid where ID = oldid;
        update `Borrow` set readerID = newid where readerID = oldid;
        update `Reserve` set readerID = newid where readerID = oldid;
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
