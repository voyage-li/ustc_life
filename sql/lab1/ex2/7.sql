select r.ID, r.name, count(*) as cn from `Reader` r, `Borrow` b
where r.ID = b.readerID group by r.ID
order by cn desc
limit 10;