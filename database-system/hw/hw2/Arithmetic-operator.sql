-- Arithmetic operator
SELECT Name, District, population * 1.5 as NewPopulation
FROM world.city
where District = 'Kabol';