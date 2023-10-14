-- #Week6, Nested Query
select Name as CountryName
from country
where Code in (select CountryCode from countrylanguage where Language = 'Korean');