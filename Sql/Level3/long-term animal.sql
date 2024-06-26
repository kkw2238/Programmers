-- https://school.programmers.co.kr/learn/courses/30/lessons/59044
SELECT a.name, a.datetime 
FROM animal_ins AS a
    LEFT OUTER JOIN animal_outs AS b
        ON a.animal_id = b.animal_id
WHERE b.animal_id IS NULL
ORDER BY a.datetime
LIMIT 3