-- #Week6, Task1-3
SELECT C.Name
FROM country C
WHERE Continent = 'Europe'
AND C.Code IN
(SELECT L.CountryCode 
FROM CountryLanguage L
WHERE L.Language = 'English' and L.Percentage > 50);