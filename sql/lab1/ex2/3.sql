select author from `Book`, `Borrow`
where `Book`.ID = `Borrow`.bookID
group by `Book`.author
having count(*) = (
    select max(cn) from (
        select count(*) as cn from `Book`, `Borrow`
        where `Book`.ID = `Borrow`.bookID
        group by `Book`.author
    ) as newtable
);