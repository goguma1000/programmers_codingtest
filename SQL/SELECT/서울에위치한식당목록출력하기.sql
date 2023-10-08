SELECT INFO.REST_ID, INFO.REST_NAME, INFO.FOOD_TYPE, INFO.FAVORITES, INFO.ADDRESS, ROUND(AVG(REVIEW_SCORE),2) AS SCORE
FROM REST_INFO AS INFO, REST_REVIEW AS REVIEW
WHERE INFO.ADDRESS LIKE '서울%' AND INFO.REST_ID = REVIEW.REST_ID
GROUP BY INFO.REST_ID
ORDER BY SCORE DESC, INFO.FAVORITES DESC;
