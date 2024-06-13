/*
	https://programmers.co.kr/learn/courses/30/lessons/12912?language=cpp
*/

const long long Abs(const int num)
{
    if (num < 0)
    {
        return -num;
    }

    return num;
}

long long solution(int a, int b) {
    long long n = Abs(a - b) + 1;
    
    /*
        등차 수열의 합 = n * (a + b) / 2 공식 이용 
    */

    return n * (a + b) / 2;
}