import java.util.Arrays;

public class Sortbyinteger {
     public static long solution(long n)
    {
        char[] str = String.valueOf(n).toCharArray();
        Arrays.sort(str);
        
        String s = new StringBuilder(new String(str)).reverse().toString();

        return Long.parseLong(s);
    }
}
