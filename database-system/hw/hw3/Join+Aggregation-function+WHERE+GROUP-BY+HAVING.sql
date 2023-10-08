-- #Week5, JOIN+Aggregation Function+WHERE+GROUP-BY+HAVING
select C.Name as Country_Name, count(*) as Filtered_Country_Count
from city T, country C
where T.CountryCode = C.Code
group by C.Name
having count(*) >= 70;