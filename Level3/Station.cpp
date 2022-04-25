/*
	https://programmers.co.kr/learn/courses/30/lessons/12979
*/

#include <vector>
#include <queue>

using namespace std;

struct WifiRange {
	int beginWifiIndex;
	int endWifiIndex;
};

int GetEstablishStationCount(int offset, int range)
{
	int stationCount = offset / range;

	if (offset % range > 0)
	{
		++stationCount;
	}

	return stationCount;
}

int solution(int n, vector<int> stations, int w)
{
	queue<WifiRange> wifiStation;

	int answer = 0;
	int memEndIndex = 1;

	for (int station : stations)
	{
		int beginWifi = max(station - w, 1);
		int endWifi = min(station + w, n);

		wifiStation.push({ beginWifi, endWifi });
	}
	
	while (!wifiStation.empty())
	{
		WifiRange stationRange = wifiStation.front();
		wifiStation.pop();

		if (stationRange.beginWifiIndex > memEndIndex)
		{
			int offset = stationRange.beginWifiIndex - memEndIndex;
			answer += GetEstablishStationCount(offset, w * 2 + 1);
		}

		memEndIndex = stationRange.endWifiIndex;
	}

	if (memEndIndex != n)
	{
		int offset = n - memEndIndex;
		answer += GetEstablishStationCount(offset, w * 2 + 1);
	}

	return answer;
}

/*
const int STATION = 1;
const int WAVE_REACH = 2;

void BuildStation(const int n, vector<int>& waveReach, const int pos, const int w) {
	for (int i = 0; i <= w; ++i)
	{
		if (i == 0)
		{
			waveReach[pos] = STATION;
		}
		else
		{
			if (pos - i >= 0)
			{
				waveReach[pos - i] = WAVE_REACH;
			}
			if (pos + i < n)
			{
				waveReach[pos + i] = WAVE_REACH;
			}
		}
	}
}

bool IsEnableBuild(int pos, int w, vector<int>& waveReach) {
	int rightEnd = (pos + w) < waveReach.size() ? pos + w : waveReach.size() - 1;

	if (!waveReach[pos - w] || !waveReach[rightEnd]) return true;
	if (!waveReach[((pos - w) + pos) / 2] || !waveReach[((rightEnd)+pos) / 2]) return true;
	if (!waveReach[pos - 1] || !waveReach[pos + 1]) return true;
	return !waveReach[pos];
}

int solution(int n, vector<int> stations, int w)
{
	int result = 0;
	vector<int> waveReach(n);

	for (int station : stations)
	{
		BuildStation(n, waveReach, station - 1, w);
	}

	for (int i = w; i <= n - w; ++i) {
		if (waveReach[i] == 0 )
		{
			if(i + w < n && waveReach[i + w] == 0)
			{
				BuildStation(n, waveReach, i + w, w);
			}
			else
			{
				BuildStation(n, waveReach, w, w);
			}
			++result;
		}
	}

	return result;
}

*/