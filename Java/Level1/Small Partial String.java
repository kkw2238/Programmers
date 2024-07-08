/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/147355
 */

class Solution {
    public int solution(String t, String p) {
        int answer = 0;
        long parseP = Long.parseLong(p);

        for(int i = 0; i <= t.length() - p.length(); ++i)
        {
            String str = t.substring(i, i + p.length());

            if(Long.parseLong(str) <= parseP)
            {
                ++answer;
            }
        }

        return answer;
    }
}