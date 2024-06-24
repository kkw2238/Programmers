-- https://school.programmers.co.kr/learn/courses/30/lessons/132201

SELECT pt_name, pt_no, gend_cd, age, IF(ISNULL(tlno), 'NONE', tlno) as tlno
FROM patient
WHERE age <= 12 AND gend_cd = 'W'
ORDER BY age desc, pt_name