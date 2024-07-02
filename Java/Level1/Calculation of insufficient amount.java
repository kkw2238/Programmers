/*
	https://school.programmers.co.kr/learn/courses/30/lessons/82612?language=java
*/

class Solution {
    public long solution(int price, int money, int count) {
        return Math.max(0L, (count * (price + (long)price * count) / 2 - money));
    }
}