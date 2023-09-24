-- OR operator
SELECT Code, Name, Continent, Region
FROM world.country
WHERE Continent = 'Asia' OR Continent = 'South America';