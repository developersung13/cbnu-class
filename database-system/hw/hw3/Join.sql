-- #Week5, JOIN
select C.Name as Country_Name, T.Name as Capital
from city T, country C
where T.CountryCode = C.Code
group by C.Name