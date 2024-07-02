-- https://school.programmers.co.kr/learn/courses/30/lessons/59411
SELECT i.animal_id, i.name
FROM animal_ins as i JOIN animal_outs as o
    ON i.animal_id = o.animal_id
WHERE o.animal_id IS NOT NULL
ORDER BY o.datetime - i.datetime DESC
LIMIT 2