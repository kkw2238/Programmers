/*
    https://school.programmers.co.kr/learn/courses/30/lessons/12918?language=java
*/

class Solution {
    public boolean solution(String s) {
        boolean answer = true;
        if(s.length() != 4 && s.length() != 6)
        {
            return false;
        }
        
        for(int i = 0; i < s.length(); ++i)
        {
            if(!Character.isDigit(s.charAt(i)))
            {
                return false;
            }
        }

        return true;
    }
}