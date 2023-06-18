-- Active: 1685774839374@@127.0.0.1@3306@lab1
select ID, name from `Reader`
where not exists (select * from `Borrow` where ID = `Borrow`.readerID)
    and not exists (select * from `Reserve` where ID = `Reserve`.readerID);