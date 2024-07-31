/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/42840?language=java
 */
import java.util.ArrayList;
import java.util.List;

class Solution {
    public Integer[] solution(int[] answers) {
        final int[][] STUDENT_ANSWER = { { 1, 2, 3, 4, 5 }, { 2, 1, 2, 3, 2, 4, 2, 5 }, { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 } };
        int[] points = { 0, 0, 0 };

        for(int question = 0; question < answers.length; ++question)
        {
            for(int i = 0; i < STUDENT_ANSWER.length; ++i) 
            {
                if(STUDENT_ANSWER[i][question % STUDENT_ANSWER[i].length] == answers[question])
                {
                    ++points[i];
                }
            }
        }
        
        List<Integer> pocket = new ArrayList<Integer>();
        int max = 0;

        for(int i = 0; i < 3; ++i)
        {
            if(points[i] > max)
            {
                pocket.clear();
                pocket.add(i + 1);
                max = points[i];
            }
            else if(points[i] == max)
            {
                pocket.add(i + 1);
            }
        }
        Integer[] answer = new Integer[pocket.size()];
        pocket.toArray(answer);
        return answer;
    }
}