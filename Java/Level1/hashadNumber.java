public class hashadNumber {
    public boolean solution(int x) {
        int hashad = 0, memX = x;
        
        while(x > 0) {
            hashad += x % 10;
            x /= 10;
        }

        return (memX % hashad) == 0;
    }
}
