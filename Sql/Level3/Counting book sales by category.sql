-- https://school.programmers.co.kr/learn/courses/30/lessons/144855

SELECT a.category, SUM(b.sales) as total_sales
FROM book as a JOIN book_sales as b
    ON a.book_id = b.book_id
WHERE YEAR(b.sales_date) = 2022 AND MONTH(b.sales_date) = 1 
GROUP BY a.category
ORDER BY category