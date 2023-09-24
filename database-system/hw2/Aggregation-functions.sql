-- Aggregation functions
SELECT AVG(population) as avgPopulation, MAX(population) as maxPopulation
FROM world.city
where District = 'Buenos Aires';