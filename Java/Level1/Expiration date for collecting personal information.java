/*
 *  https://school.programmers.co.kr/learn/courses/30/lessons/150370
 */

import java.util.List;
import java.util.ArrayList;

class Solution {
    final int MONTH_OF_DAY = 28;
    final int YEAR_OF_DAY = 28 * 12;
    final int MINIMUM_YEAR = 2000;

    public int parseDate(String date) {
        int parsedDate = 0;
        String[] dates = date.split("[.]");
        
        parsedDate += (Integer.parseInt(dates[0]) - MINIMUM_YEAR) * YEAR_OF_DAY;
        parsedDate += (Integer.parseInt(dates[1]) - 1) * MONTH_OF_DAY;
        parsedDate += (Integer.parseInt(dates[2]) - 1);

        return parsedDate;
    }

    public int[] solution(String today, String[] terms, String[] privacies) {
        int[] type = new int[26];
        List<Integer> pastPrivacy = new ArrayList<>();
        int parsedToday = parseDate(today);

        for (String term : terms) {
            String[] splitTerm = term.split(" ");
            int typeIndex = splitTerm[0].charAt(0) - 'A';

            type[typeIndex] = Integer.parseInt(splitTerm[1]) * MONTH_OF_DAY;
        }

        for (int i = 0; i < privacies.length; ++i) {
            String[] privacy = privacies[i].split(" ");
            int privacyRange = type[privacy[1].charAt(0) - 'A'];
            int expirationDate = parseDate(privacy[0]) + privacyRange;

            if(parsedToday > expirationDate) {
                pastPrivacy.add(i + 1);
            }
        }

        return pastPrivacy.stream()
            .mapToInt(i -> i)
            .toArray();
    }
}