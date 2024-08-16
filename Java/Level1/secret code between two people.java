/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/155652
 */

 class Solution {
    public char doSkip(char c, boolean[] isSkipable, int index) {
        int alphaOffset = c - 'a';

        for (int i = 0; i < index;) {
            alphaOffset = (alphaOffset + 1) % 26;
            if (!isSkipable[alphaOffset]) {
                ++i;
            }
        }

        return (char)('a' + alphaOffset);
    }
    
    public String solution(String s, String skip, int index) {
        StringBuilder answer = new StringBuilder("");
        
        // 스킵해야하는 알파벳 여부
        boolean[] isSkipable = new boolean[26];
        // i번째 알파벳이 인덱스 만큼 증가 했을 때 최종 위치
        char[] afterSkip = new char[26];

        for (int i = 0; i < skip.length(); ++i) {
            int alphaIndex = skip.charAt(i) - 'a';
            isSkipable[alphaIndex] = true;
        }

        for(int i = 0; i < s.length(); ++i) {
            int alphaIndex = s.charAt(i) - 'a';
            if (afterSkip[alphaIndex] == 0) {
                afterSkip[alphaIndex] = doSkip(s.charAt(i), isSkipable, index);
            }

            answer.append(afterSkip[alphaIndex]);
        }

        return answer.toString();
    }
}