/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/161990?language=java
 */
class Solution {
    public void refreshRange(int[] ranges, int x, int y) {
        ranges[1] = Integer.min(ranges[1], x);
        ranges[0] = Integer.min(ranges[0], y);
        ranges[3] = Integer.max(ranges[3], x);
        ranges[2] = Integer.max(ranges[2], y);

    }

    public int[] solution(String[] wallpaper) {
        int[] ranges = { Integer.MAX_VALUE, Integer.MAX_VALUE, Integer.MIN_VALUE, Integer.MIN_VALUE };

        for(int y = 0; y < wallpaper.length; ++y) {
            for(int x = 0; x < wallpaper[y].length(); ++x) {
                if (wallpaper[y].charAt(x) == '#') {
                    refreshRange(ranges, x, y);
                }
            }
        }

        return ranges;
    }
}