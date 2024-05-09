select `Book`.ID, `Book`.name from `Book`, `Borrow`
where `Book`.ID = `Borrow`.bookID 
and `Borrow`.returnDate is null and `Book`.name like '%MySQL%';