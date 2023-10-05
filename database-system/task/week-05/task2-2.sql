-- #Week5, Task2-2
select C.Name as Country_Name, L.Language as Country_Language
from country C, countrylanguage L
where C.Code = L.CountryCode
and L.Language = 'Korean';