-- Active: 1682256568013@@127.0.0.1@3306@lab3

drop procedure if exists inpaper;
drop procedure if exists addpaper;



delimiter //
create procedure inpaper(in name char(255), in pafrom char(255), in payear date, in patype int, in palevel int, out ret paID)
label1:begin

end //

create procedure addpaper(in TeNum char(5), int paid in ran int, in Isau boolean, out ret int)
label2:begin
	set ret = 0;
    start transaction;
	if exists(select * from PostPaper where PaperID = paid and PostRank = ran) or 
    (Isau = true and exists(select * from PostPaper where PaperID = paid and IsAuthor = true)) then
	    set ret = -1;
        rollback;
	    leave label2;
	end if;
	insert into PostPaper value(TeNum, paid, ran, Isau);
	end // 
delimiter ;