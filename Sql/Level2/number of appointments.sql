-- https://school.programmers.co.kr/learn/courses/30/lessons/132202

SELECT mcdp_cd as '진료과코드', count(*) as '5월예약건수'
FROM appointment
WHERE YEAR(apnt_ymd) = 2022 AND MONTH(apnt_ymd) = 05
GROUP BY mcdp_cd
ORDER BY COUNT(mcdp_cd), mcdp_cd