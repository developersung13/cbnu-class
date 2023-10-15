-- #Week6, Task1-2
select name, population
from country
where population > (
	select population 
	from country
	where code = 'USA'
)
order by population desc;