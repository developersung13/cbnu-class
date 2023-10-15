-- #Week6, Task1-5
SELECT count(*) from city
UNION 
SELECT count(*) from country
UNION 
SELECT count(*) from countrylanguage
UNION 
SELECT count(*) from city , country , countrylanguage ;