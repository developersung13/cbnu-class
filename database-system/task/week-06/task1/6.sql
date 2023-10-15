-- #Week6, Task1-6
SELECT CountryCode, IsOfficial, count(Language) as LanguageCount
FROM    countrylanguage
WHERE   IsOfficial = 'T'
GROUP BY CountryCode
HAVING COUNT(Language) > 1
UNION ALL
SELECT CountryCode, IsOfficial, count(Language) as LanguageCount
FROM    countrylanguage
WHERE   IsOfficial = 'F'
GROUP BY CountryCode
HAVING COUNT(Language) > 2
ORDER BY CountryCode;