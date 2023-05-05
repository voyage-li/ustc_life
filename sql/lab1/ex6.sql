-- Active: 1682256568013@@127.0.0.1@3306@lab1
drop trigger if exists updateRe;
drop trigger if exists updateBo;

delimiter //
create trigger updateRe after insert on `Reserve` for each row
begin
    update `Book` set status = if(status = 1, 1, 2), reserveTimes = reserveTimes + 1 where ID = new.bookID;
end//
delimiter ;

delimiter //
create trigger updateBo after delete on `Reserve` for each row
begin
    update `Book` set reserveTimes = reserveTimes - 1 where ID = old.bookID;
end//
delimiter ;