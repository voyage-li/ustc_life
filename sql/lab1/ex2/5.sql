select `Reader`.name from `Reader`, `Borrow`
where `Reader`.ID = `Borrow`.readerID
group by `Reader`.ID
having count(*) >= 10;