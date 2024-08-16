/*
 *  https://school.programmers.co.kr/learn/courses/30/lessons/160586?language=java
 */

import java.util.Arrays;

class Solution {
    public int[] solution(String[] keymap, String[] targets) {
        int[] touchKeymap = new int[26];
        int[] answer = new int[targets.length];

        Arrays.fill(touchKeymap, Integer.MAX_VALUE);

        for (String km : keymap) {
            for (int i = 0; i < km.length(); ++i) {
                int alphaIndex = km.charAt(i) - 'A';
                touchKeymap[alphaIndex] = Integer.min(touchKeymap[alphaIndex], i + 1);
            }
        }

        for (int i = 0; i < targets.length; ++i) {
            for (int j = 0; j < targets[i].length(); ++j) {
                int alphaIndex = targets[i].charAt(j) - 'A';

                if(touchKeymap[alphaIndex] == 0) {
                    answer[i] = -1;
                    break;
                } else {
                    answer[i] += touchKeymap[alphaIndex];
                }
            }
        }

        return answer;
    }
}