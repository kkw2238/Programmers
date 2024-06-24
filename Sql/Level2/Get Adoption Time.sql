-- https://school.programmers.co.kr/learn/courses/30/lessons/59412

SELECT HOUR(datetime) as HOUR, COUNT(HOUR(datetime)) as count
FROM animal_outs
WHERE HOUR(datetime) BETWEEN 9 and 19
GROUP BY HOUR(datetime)
ORDER BY HOUR(datetime)