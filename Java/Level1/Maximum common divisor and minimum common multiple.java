/*
 *  https://school.programmers.co.kr/learn/courses/30/lessons/12940?language=java
 */

 class Solution {
    public int swap(int a, int b)
    {
        return a;
    }

    public int euclidean(int a, int b)
    {
        int minNum = Math.min(a, b);
        int maxNum = Math.max(a, b);

        while(maxNum % minNum != 0)
        {
            maxNum = maxNum % minNum;
            minNum = swap(maxNum, maxNum = minNum);
        }

        return minNum;
    }

    public int[] solution(int n, int m) {
        int gdc = euclidean(n, m);

        return new int[]{ gdc, n * m / gdc };
    }
}