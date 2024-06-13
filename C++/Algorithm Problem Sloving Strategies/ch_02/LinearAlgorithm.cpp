#include <vector>

using namespace std;

/// <summary>
///		* Sum(A[N]) = A[0] + A[1] + A[2] + ... + A[N]
///		
///		A[N] ~ A[N + M]까지의 합 = SUM(A[N + M]) - SUM(A[N - 1])
/// </summary>

vector<double> movingAverageLinearTime(const vector<double>& A, int M)
{
	vector<double> average;
	double sumPartial = 0.0;

	for (int i = 0; i < A.size(); ++i)
	{
		if (i >= M)
		{
			sumPartial -= A[i - M];
		}

		sumPartial += A[i];
		average.push_back(sumPartial / (double)M);
	}

	return average;
}