-- LIKE #1 operator
SELECT Code, Name, Continent, Region
FROM world.country
WHERE Name LIKE 'U%S';