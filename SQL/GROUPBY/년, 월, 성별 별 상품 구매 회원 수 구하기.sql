SELECT YEAR(SALES_DATE) AS YEAR, MONTH(SALES_DATE) AS MONTH, GENDER, COUNT(*) AS USERS
FROM USER_INFO AS U 
        JOIN (SELECT *
              FROM ONLINE_SALE
              GROUP BY YEAR(SALES_DATE), MONTH(SALES_DATE), USER_ID)AS O 
        ON U.USER_ID = O.USER_ID
WHERE GENDER IS NOT NULL
GROUP BY YEAR, MONTH, GENDER
ORDER BY YEAR, MONTH, GENDER
