-- #Week5, Task2-1
select T.Name as City_Name, C.Name as Located_Country_Name
from city T, country C
where T.CountryCode = C.Code
and T.Name = 'Berlin';