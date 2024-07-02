-- https://school.programmers.co.kr/learn/courses/30/lessons/59045#fn1

SELECT i.animal_id, i.animal_type, i.name
FROM animal_ins as i INNER JOIN animal_outs as o
     ON i.animal_id = o.animal_id
 WHERE i.sex_upon_intake LIKE 'Intact%' AND o.sex_upon_outcome NOT LIKE 'Intact%'
 ORDER BY i.animal_id