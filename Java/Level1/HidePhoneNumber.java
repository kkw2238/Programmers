/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/12948
 */

class Solution {
    public String solution(String phone_number) {
        String substr = phone_number.substring(phone_number.length() - 4);
        String masking = new String("*").repeat(phone_number.length() - 4);

        return masking + substr;
    }
}