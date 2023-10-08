-- #Week5, JOIN+WHERE+AND+AND operator+ORDER BY
select C.Name as Country_Name, T.Name as Capital, T.Population
from city T, country C
where T.CountryCode = C.Code
and C.Name = 'South Korea'
and T.Population > 1000000
order by T.Population desc;