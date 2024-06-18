-- https://school.programmers.co.kr/learn/courses/30/lessons/59409

SELECT ANIMAL_ID, NAME, IF(sex_upon_intake LIKE 'Neutered%' 
   OR sex_upon_intake LIKE 'Spayed%', 'O', 'X')  as 중성화
FROM animal_ins
ORDER BY animal_id