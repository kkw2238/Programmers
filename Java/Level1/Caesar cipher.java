/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/12926
 */
class Solution {
    public String solution(String s, int n) {
        String answer = "";
        char[] charArr = s.toCharArray();

        for(int i = 0; i < charArr.length; ++i)
        {
            if(Character.isUpperCase(charArr[i]))
            {
                charArr[i] = (char)('A' + (charArr[i] - 'A' + n) % 26);
            }
            else if(Character.isLowerCase(charArr[i]))
            {
                charArr[i] = (char)('a' + (charArr[i] - 'a' + n) % 26);
            }
        }

        answer = String.copyValueOf(charArr);
        return answer;
    }
}