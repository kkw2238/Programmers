/*
	https://school.programmers.co.kr/learn/courses/30/lessons/12917
*/
	
import java.util.Arrays;
import java.util.Collections;

class Solution {
    public String solution(String s) {
        Character[] characters = s.chars()
        .mapToObj(c -> (char) c)
        .toArray(Character[]::new);

        Arrays.sort(characters,Collections.reverseOrder());

        String result = Arrays.stream(characters)
            .collect(StringBuilder::new, StringBuilder::append, StringBuilder::append)
            .toString();

        return result;
    }
}