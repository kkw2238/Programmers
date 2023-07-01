/*
	https://school.programmers.co.kr/learn/courses/30/lessons/140105
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n, int count) {
    int answer = 0;

    if (n == count)
    {
        return 1;
    }
    /*
    * 11223344


        fib( 4 ) = fib( 3 ) * 3 + fib( 2 ) * 4
        fib( 3 ) = fib( 2 ) * 3 + fib( 1 ) * 2 = fib( 2 ) * 3 + fib( 1 ) * 6 = 15
        fib( 2 ) = fib( 1 ) * 3 + fib( 0 ) * 1 = 3
        fib( 1 ) = 1


        44 33 22 11 = fib( 3 ) * 2
        33 44 22 11 = fib( 2 ) * 2 * 3

        4 33 22 11 4 = fib( 3 )
        4 33 4 22 11 = fib( 2 ) * 3
        4 33 22 4 11 = fib( 2 ) * 3
        33 4 22 4 11 = fib( 1 ) * 3
        33 4 22 11 4 = fib( 2 ) * 3
        33 22 4 11 4 = fib( 2 ) * 3

        f( n - 1 ) * 3
        f( n - 2 ) * 6 * 3
        
       


        11 22 33 = fib( 2 )
        11 33 22 = fib( 1 ) * fib( 1 )
        33 11 22 = fib( 1 ) * fib( 1 )
        3 11 3 22
        3 11 22 3

        11 22 33 44
        11 22 44 33 fib( 2 ) * fib( 1 )
        11          fib( 3 ) * 4 +

        4 11 22 33 4 fib( 3 )
        4 11 22 4 33 fib( 2 ) * fib( 1 )
        4 11 4 22 33 fib( 1 ) * fib( 2 )

        44 11 22 33  fib( 3 )
        11 44 22 33  fib( 2 ) * fib( 1 )
        11 22 44 33  fib( 1 ) * fib( 2 )
        11 22 33 44  fib( 3 ) 

    
    */
    return answer;
}