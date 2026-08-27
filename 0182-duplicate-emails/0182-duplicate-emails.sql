# Write your MySQL query statement below
select distinct(p.email) as Email from Person p
join person q
on p.email=q.email and p.id!=q.id;
