/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/159994?language=java
 */

class Solution {
    public String solution(String[] cards1, String[] cards2, String[] goal) {
        int index1 = 0, index2 = 0;

        for(int i = 0; i < goal.length; ++i) {
            if(index1 < cards1.length && goal[i].compareTo(cards1[index1]) == 0) {
                ++index1;
            }
            else if(index2 < cards2.length && goal[i].compareTo(cards2[index2]) == 0) {
                ++index2;
            }
            else {
                return "No";
            }
        }

        return "Yes";
    }
}