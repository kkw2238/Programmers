/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/134240?language=java
 */

class Solution {
    public String solution(int[] food) {
        String left = "", right = "";
        
        for(int i = 1; i < food.length; ++i)
        {
            int foodCount = food[i] / 2;

            String foodString = new String(Integer.toString(i)).repeat(foodCount);
            left += foodString;
            right = foodString + right;
        }

        return left + '0' + right;
    }
}