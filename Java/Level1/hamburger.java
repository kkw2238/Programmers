/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/133502
 */
class Solution {
    public int solution(int[] ingredient) {
        int answer = 0;
        StringBuilder patty = new StringBuilder();

        for(int n : ingredient) {
            patty.append(String.valueOf(n));

            if (patty.length() >= 4 && patty.substring(patty.length() - 4).equals("1231")) {
                ++answer;
                patty.delete(patty.length() - 4, patty.length());
            }
        }

        return answer;
    }
}