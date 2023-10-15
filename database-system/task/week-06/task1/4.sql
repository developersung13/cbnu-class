-- #Week6, Task1-4
SELECT country.Name, Language AS "Main Language", percentage, city.Name AS "Capital" 
FROM country
JOIN city ON country.Capital = city.ID
JOIN countrylanguage ON country.Code = countrylanguage.CountryCode
WHERE country.Name = 'Uzbekistan'
ORDER BY percentage DESC
LIMIT 1;