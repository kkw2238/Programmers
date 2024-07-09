-- https://school.programmers.co.kr/learn/courses/30/lessons/131530
SELECT FLOOR(price / 10000) * 10000 as price_group, count(*) as products
FROM product
GROUP BY FLOOR(price / 10000)
ORDER BY price