-- https://school.programmers.co.kr/learn/courses/30/lessons/157341
SELECT DISTINCT c.car_id
FROM car_rental_company_car as c INNER JOIN car_rental_company_rental_history as h
    ON c.car_id = h.car_id
WHERE c.car_type = '세단' AND MONTH(h.start_date) = 10
ORDER BY car_id DESC