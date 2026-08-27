# Write your MySQL query statement below
select distinct(p.email) as Email from Person p
where p.email in (select q.email from Person q where p.id!=q.id);
