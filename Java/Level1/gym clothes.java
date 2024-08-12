/*
 *  https://school.programmers.co.kr/learn/courses/30/lessons/42862?language=java
 */

class Solution {
    public void lend(int[] clothes, int to, int from) {
        ++clothes[to];
        --clothes[from];
    }

    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        int[] clothes = new int[n + 1];

        for (int l : lost) {
            clothes[l] = -1;
        }
        
        for (int r : reserve) {
            clothes[r] += 1;
        }

        for (int i = 1; i <= n; ++i) {
            if(clothes[i] == -1) {
                if(clothes[i - 1] == 1) {
                    lend(clothes, i, i - 1);
                } else if(i < n && clothes[i + 1] == 1) {
                    lend(clothes, i, i + 1);
                }
            } 
            if(clothes[i] >= 0) {
                ++answer;
            }
        }
    
        return answer;
    }
}