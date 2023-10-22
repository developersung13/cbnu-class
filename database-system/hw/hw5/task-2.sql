SELECT Name, top.counter2 as NumOfLanguages
FROM Country, 
	(SELECT CountryCode, count(*) as counter2
	FROM countrylanguage
	WHERE IsOfficial = 'T'
	GROUP BY CountryCode
	HAVING counter2 = (
		SELECT max(counter) as maxcounter
		FROM(
			SELECT CountryCode, count(*) as counter
			FROM countrylanguage
			WHERE IsOfficial = 'T'
			GROUP BY CountryCode
			ORDER BY counter DESC)
		AS maxnumber
	)
)as top
WHERE Country.code=top.countrycode;