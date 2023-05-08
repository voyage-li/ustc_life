-- Active: 1682256568013@@127.0.0.1@3306@lab1
select bo.bookID, b.name, bo.borrowDate
from `Book` b, `Reader` r, `Borrow` bo
where b.ID = bo.bookID and r.ID = bo.readerID and r.name = 'Rose';