-- #Week5, Task2-5
SET GLOBAL sql_mode=(SELECT REPLACE(@@sql_mode,'ONLY_FULL_GROUP_BY',''));

-- MySQL Workbench Restart!!

select C.NAME as Country, T.Name as City, MAX(T.Population) as Population
from city T, country C
where C.Code = T.CountryCode
group by C.Name
having COUNT(T.ID) > 9
order by Population desc;