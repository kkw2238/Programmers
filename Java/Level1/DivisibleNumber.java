/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/12910
 */

import java.util.ArrayList;
import java.util.Arrays;

public class Solution {
    public int[] solution(int[] arr, int divisor) {
        ArrayList<Integer> result = new ArrayList<>();
        for(int n : arr)
        {
           if(n % divisor == 0)
           {
                result.add(n);
           } 
        }

        int[] answer = result.stream().mapToInt(Integer::intValue).toArray();
        if(answer.length == 0)
        {
            return new int[] {-1};
        }
        
        Arrays.sort(answer);
        return answer;
    }
}
