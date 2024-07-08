/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/12930?language=java
 */

 class Solution {
    public String solution(String s) {
        String answer = "";
        char[] chars = s.toCharArray();
        int index = 0;

        for(int i = 0; i < chars.length; ++i)
        {
            if(Character.isSpaceChar(chars[i]))
            {
                index = 0;
            }
            else
            {
                if(index % 2 == 0)
                {
                    chars[i] = Character.toUpperCase(chars[i]);
                }
                else
                {
                    chars[i] = Character.toLowerCase(chars[i]);
                }

                index++;
            }

            answer += chars[i];
        }

        return answer;
    }
}