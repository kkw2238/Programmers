public class AddBetweenTwoNumber {
    public long solution(int a, int b) {
        return (long)(Math.abs(a - b) + 1) * (long)(a + b) / 2;
    }
}
