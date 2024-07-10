-- https://school.programmers.co.kr/learn/courses/30/lessons/131120
SELECT member_id, member_name, gender, DATE_FORMAT(date_of_birth, '%Y-%m-%d') as date_of_birth
FROM member_profile
WHERE MONTH(date_of_birth) = 3 AND tlno != 'NULL' AND GENDER = 'W'
ORDER BY member_id ASC