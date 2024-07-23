/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/42748?language=java
 */

import java.util.Arrays;

class Solution {

    public int[] cutArray(int[] array, int begin, int end)
    {
        final int size = end - begin + 1;
        int[] result = new int[size];

        for(int i = 0; i < size; ++i)
        {
            result[i] = array[begin + i];
        }

        return result;
    }

    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];

        for(int i = 0; i < commands.length; ++i)
        {
            int[] cuttedArray = cutArray(array, commands[i][0] - 1, commands[i][1] - 1);

            Arrays.sort(cuttedArray);
            answer[i] = cuttedArray[commands[i][2] - 1];
        }

        return answer;
    }
}