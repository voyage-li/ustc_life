select r.ID, r.name, count(*) as cn from `Reader` r, `Borrow` b
where r.ID = b.readerID and year(b.borrowDate) = 2022 group by r.ID
order by cn desc
limit 10;