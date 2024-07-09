/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/86491?language=java
 */

 class Solution {
    public int solution(int[][] sizes) {
        int walletWidth = 0, walletHeight = 0;

        for(int[] size : sizes)
        {
            int biggerSize = Math.max(size[0], size[1]);
            int smallerSize = Math.min(size[0], size[1]);

            walletWidth = Math.max(biggerSize, walletWidth);
            walletHeight = Math.max(smallerSize, walletHeight);
        }

        return walletWidth * walletHeight;
    }
}