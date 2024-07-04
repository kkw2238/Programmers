-- https://school.programmers.co.kr/learn/courses/30/lessons/131113
SELECT 
    order_id, 
    product_id, 
    DATE_FORMAT(out_date, '%Y-%m-%d') as out_date, 
    IF(out_date IS NULL, '출고미정', 
        IF(out_date <= DATE('2022-05-01'), '출고완료', '출고대기')
      ) as '출고여부'
FROM food_order
ORDER BY order_id