/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/68644?language=java
 */
import java.util.Set;
import java.util.TreeSet;

class Solution {
    public int[] solution(int[] numbers) {
        Set<Integer> answerContainer = new TreeSet<Integer>();

        for(int i = 0; i < numbers.length; ++i)
        {
            for(int j = i + 1; j < numbers.length; ++j)
            {
                answerContainer.add(numbers[i] + numbers[j]);
            }
        }

        int[] answer = new int[answerContainer.size()];
        int index = 0;
        for(Integer inte : answerContainer)
        {
            answer[index++] = inte;
        }

        return answer;
    }
}