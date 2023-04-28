/*
	https://school.programmers.co.kr/learn/courses/30/lessons/135807
*/

#include <string>
#include <vector>

using namespace std;

int gdc(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gdc(b, a % b);
    }
}

int getArrayGDC(const vector<int>& arrayA)
{
    int memGDC = arrayA[0];

    for (int i = 1; i < arrayA.size(); ++i)
    {
        int maxData = max(arrayA[i], memGDC);
        int minData = min(arrayA[i], memGDC);
        
        if (arrayA[i] % memGDC == 0)
        {
            continue;
        }

        memGDC = gdc(maxData, minData);
    }
    return memGDC;
}

int distinctionGDC(const vector<int>& arrayA, int gdcB)
{
    if (gdcB != 1)
    {
        for (int a : arrayA)
        {
            if (a % gdcB == 0)
            {
                gdcB = 0;
                break;
            }
        }
    }
    else
    {
        gdcB = 0;
    }

    return gdcB;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int gdcA = getArrayGDC(arrayA);
    int gdcB = getArrayGDC(arrayB);
    
    gdcA = distinctionGDC(arrayB, gdcA);
    gdcB = distinctionGDC(arrayA, gdcB);

    if (gdcA > 0 && gdcB > 0)
    {
        return 0;
    }
    
    return max(gdcA, gdcB);
}