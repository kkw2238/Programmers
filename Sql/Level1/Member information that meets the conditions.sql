-- https://school.programmers.co.kr/learn/courses/30/lessons/131535

SELECT COUNT(USER_ID) as USERS
FROM USER_INFO
WHERE AGE >= 20 AND AGE <= 29 AND YEAR(JOINED) = 2021 