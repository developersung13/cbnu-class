-- #Week6, Task1-1
SELECT Name, Population
FROM Country
WHERE Continent = 'Asia'
ORDER BY Population DESC
LIMIT 1;