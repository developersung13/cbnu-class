SELECT Continent, Name, MAX(DerivedLanguage.NumOfLanguages) AS 'Non-Official Languages'
FROM
	(SELECT C.Name, C.Continent, L.CountryCode, count(*) as NumOfLanguages
	FROM CountryLanguage L
	JOIN Country C ON C.Code = L.countryCode
	WHERE IsOfficial = 'F'
	GROUP BY CountryCode
	ORDER BY NumOfLanguages DESC) AS DerivedLanguage
GROUP BY Continent;