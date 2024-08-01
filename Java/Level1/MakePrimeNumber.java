/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/12977?language=java
 */
public class MakePrimeNumber {
    int IsFrimeNumber(int num) {
        double sqrtNum = Math.sqrt((double)num);
        
        for (int i = 2; i <= sqrtNum; ++i) 
        {
            if (num % i == 0)
            {
                return 0;
            }
        }
    
        return 1;
    }

    public int solution(int[] nums) {
        int result = 0;

	    for (int i = 0; i < nums.length - 2; ++i) 
        {
		    for (int j = i + 1; j < nums.length - 1; ++j)  
            {
			    for (int k = j + 1; k < nums.length; ++k) 
                {
			    	result += IsFrimeNumber(nums[i] + nums[j] + nums[k]);
                }
            }
        }
    
	    return result;
    }
}
