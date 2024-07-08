-- https://school.programmers.co.kr/learn/courses/30/lessons/164668
SELECT user_id, nickname, SUM(price) as total_sales
FROM used_goods_board as b INNER JOIN used_goods_user as u
    ON b.writer_id = u.user_id
WHERE b.status = 'DONE'
GROUP BY b.writer_id
HAVING SUM(price) >= 700000
ORDER BY total_sales