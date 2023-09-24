-- Aggregation function + WHERE + GROUP BY + HAVING + LIMIT
SELECT AVG(population) as avgPopulation
FROM world.city
WHERE District LIKE 'K%'
GROUP BY District
HAVING avgPopulation > 50000
ORDER BY avgPopulation
LIMIT 5;