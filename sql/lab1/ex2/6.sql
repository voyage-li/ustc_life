select r.ID, r.name from `Reader` r
where not exists(
    select * from `Book`, `Borrow`
    where `Borrow`.bookID = `Book`.ID 
        and r.ID = `Borrow`.readerID and `Book`.author = 'John'
)