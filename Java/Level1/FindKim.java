/* 
	https://school.programmers.co.kr/learn/courses/30/lessons/12919?language=java
*/

import java.util.Arrays;

class Solution {
    public String solution(String[] seoul) {
        int index = Arrays.asList(seoul).indexOf("Kim");
        
        return String.format("김서방은 %d에 있다", index);
    }
}