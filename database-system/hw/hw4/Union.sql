-- #Week6, Union
select 'city' as TableNameRelatedToKorea, count(*) as Cardinality  from city where CountryCode = 'KOR'
union
select 'countrylanguage', count(*) from countrylanguage where CountryCode = 'KOR';