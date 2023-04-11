select bo.bookID, b.name, date_format(bo.borrowDate,"%Y-%m-%d")
from `Book` b, `Reader` r, `Borrow` bo
where b.ID = bo.bookID and r.ID = bo.readerID and r.name = 'Rose';