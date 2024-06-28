-- https://school.programmers.co.kr/learn/courses/30/lessons/131533
SELECT product_code, SUM(product.price * offline_sale.sales_amount) as sales
FROM product JOIN offline_sale
    ON product.product_id = offline_sale.product_id
GROUP BY product.product_id
ORDER BY sales DESC, product.product_code