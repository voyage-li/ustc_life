select ID, name from `Reader`
where not exists (select * from `Borrow` where ID = `Borrow`.readerID)
    and not exists (select * from `Reserve` where ID = `Reserve`.readerID);