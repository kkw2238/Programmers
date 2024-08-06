/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/77484
 */
import java.util.Arrays;

class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = {0, 0};

        int lottoIndex = 0;
        int winNumsIndex = 0;
        int joker = 0;
        int matchCount = 0;

        Arrays.sort(lottos);
        Arrays.sort(win_nums);

        while(lottoIndex < lottos.length && winNumsIndex < win_nums.length) {
            if(lottos[lottoIndex] == 0) {
                ++joker;
                ++lottoIndex;
                continue;
            } 

            if(lottos[lottoIndex] == win_nums[winNumsIndex]) {
                ++matchCount;
                ++lottoIndex;
                ++winNumsIndex;
            } else if(lottos[lottoIndex] > win_nums[winNumsIndex]) {
                ++winNumsIndex;
            } else {
                ++lottoIndex;
            }
        }
        
        answer[0] = Math.min(6 - (matchCount + joker - 1), 6);
        answer[1] = Math.min(6 - (matchCount - 1), 6);

        return answer;
    }
}