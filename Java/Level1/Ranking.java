/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/138477?language=java
 */

import java.util.PriorityQueue;
import java.util.Queue;

class Solution {
    public int[] solution(int k, int[] score) {
        int[] answer = new int[score.length];
        Queue<Integer> ranking = new PriorityQueue<>();
        int day = 0;

        for(int s : score)
        {
            ranking.add(s);
            if(ranking.size() > k)
            {
                ranking.poll();
            }

            answer[day++] = ranking.peek();
        }

        return answer;
    }
}