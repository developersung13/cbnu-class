-- #Week6, JOIN
select C.Name as CountryName, L.Language
from country C
join countrylanguage L on C.Code = L.CountryCode
where C.Name = 'United States';