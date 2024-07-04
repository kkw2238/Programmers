-- https://school.programmers.co.kr/learn/courses/30/lessons/133026

SELECT i.ingredient_type, SUM(f.total_order) as total_order
FROM first_half as f INNER JOIN icecream_info as i
    ON f.flavor = i.flavor
GROUP BY i.ingredient_type
ORDER BY total_order ASC