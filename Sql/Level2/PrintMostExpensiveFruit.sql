--https://school.programmers.co.kr/learn/courses/30/lessons/131115

SELECT 
    PRODUCT_ID, 
    PRODUCT_NAME, 
    PRODUCT_CD, 
    CATEGORY, 
    PRICE 
FROM FOOD_PRODUCT
ORDER BY PRICE DESC
LIMIT 1