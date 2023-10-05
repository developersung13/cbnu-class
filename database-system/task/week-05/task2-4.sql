-- #Week5, Task2-4
select C.Name as Country_Name, T.Name as Capital_Name
from city T, country C
where T.ID = C.Capital
and C.Name = 'Spain';