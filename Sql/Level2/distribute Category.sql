-- https://school.programmers.co.kr/learn/courses/30/lessons/131529

SELECT SUBSTRING(product_code, 1, 2) AS category, COUNT(product_code) as products
FROM product
GROUP BY SUBSTRING(product_code, 1, 2)