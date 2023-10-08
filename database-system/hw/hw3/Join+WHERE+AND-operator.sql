-- #Week5, JOIN+WHERE+AND operator
select C.Name as Country_Name, T.Name as Capital
from city T, country C
where T.CountryCode = C.Code
and C.Name = 'South Korea';