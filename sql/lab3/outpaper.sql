-- Active: 1685774839374@@127.0.0.1@3306@lab3

drop procedure if exists inpaper;
drop procedure if exists addpaper;



delimiter //
create procedure inpaper(in paid int, in paname char(255), in pafrom char(255), in payear date, in patype int, in palevel int, out ret int)
label1:begin
    set ret = 0;
    if exists(select * from Paper where PaperID = paid) then
        set ret = -1;
        leave label1;
    end if;
    insert into Paper value(paid, paname, pafrom, payear, patype, palevel);
end //
delimiter ;

delimiter //
create procedure addpaper(in TeNum char(5), in paid int,in ran int, in Isau boolean, out ret int)
label2:begin
	set ret = 0;
	if exists(select * from PostPaper where PaperID = paid and PostRank = ran) or 
    (Isau = true and exists(select * from PostPaper where PaperID = paid and IsAuthor = true)) then
	    set ret = -1;
	    leave label2;
	end if;
	insert into PostPaper value(TeNum, paid, ran, Isau);
end // 
delimiter ;