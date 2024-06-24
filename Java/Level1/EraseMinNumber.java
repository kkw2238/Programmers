/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/12935?language=java
 */

import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    public int[] solution(int[] arr) {
        int[] answer = {};
        ArrayList<Integer> list = new ArrayList<>();
        int minNum = Arrays.stream(arr).min().getAsInt();

        for(int n : arr)
        {
            if(n != minNum)
            {
                list.add(n);
            }
        }
        
        if(list.isEmpty())
        {
            return new int[]{-1};
        }

        return list.stream().mapToInt(Integer::intValue).toArray();
    }
}