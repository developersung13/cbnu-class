-- ORDER BY + LIMIT
SELECT ID, Name, District, population
FROM world.city
WHERE District LIKE 'K%'
ORDER BY population
LIMIT 5;