/*
 *  https://school.programmers.co.kr/learn/courses/30/lessons/131128?language=java
 */

import java.util.Arrays;

class Solution {
    public String solution(String X, String Y) {
        String answer = "";
        StringBuilder str = new StringBuilder();
        StringBuilder str2 = new StringBuilder();

        int xIndex = 0, yIndex = 0;

        char[] xChars = X.toCharArray();
        char[] yChars = Y.toCharArray();

        Arrays.sort(xChars);
        Arrays.sort(yChars);

        while(xIndex < X.length() && yIndex < Y.length()) {
            if(xChars[xIndex] == yChars[yIndex]) {
                str2.append(xChars[xIndex]);
                ++xIndex;
                ++yIndex;
            } else if (xChars[xIndex] > yChars[yIndex]) {
                ++yIndex;
            } else {
                ++xIndex;
            }
        }

        if(str2.length() == 0) {
            return "-1";
        }

        char[] resultArray = str2.toString().toCharArray();
        if(resultArray[resultArray.length - 1] == '0') {
            return "0";
        }

        answer = "";
        for(int i = resultArray.length - 1; i >= 0; --i) {
            str.append(resultArray[i]);
        }

        return str.toString();
    }
}