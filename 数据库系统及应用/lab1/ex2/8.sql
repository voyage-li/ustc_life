drop view if exists c_view;

create view c_view(readerID, readername, bookID, bookname, borrowdate) as
select `Reader`.ID, `Reader`.name, Book.ID, Book.name, `Borrow`.borrowDate
from `Reader`, Book, `Borrow`
where `Reader`.ID = `Borrow`.readerID and Book.ID = `Borrow`.bookID;

select readerID, count(distinct bookID) from c_view
where borrowdate >= date_sub(curdate(), interval 1 year)
group by readerID;