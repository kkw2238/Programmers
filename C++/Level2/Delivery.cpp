/*
	https://programmers.co.kr/learn/courses/30/lessons/12978
*/

#include <vector>

using namespace std;

const int intMax = 500000;
enum { START, DEST, COST };

vector<vector<int>> map;
vector<pair<bool, int>> visited;

void LinkVillage(const vector<int>& road)
{
	const int start = road[START];
	const int dest = road[DEST];

	if (road[COST] < map[start][dest])
	{
		map[start][dest] = road[COST];
		map[dest][start] = road[COST];
	}
}

void DFS(int start, int cost, const int limit)
{
	visited[start] = pair(true, cost);

	for (int i = 1; i < map[START].size(); ++i)
	{
		int totalCost = map[start][i] + cost;

		if (totalCost <= limit && totalCost < visited[i].second)
		{
			DFS(i, totalCost, limit);
		}
	}
}

int solution(int N, vector<vector<int>> roads, int K) {
	map = vector<vector<int>>(N + 1, vector<int>(N + 1, intMax));
	visited = vector<pair<bool, int>>(N + 1, pair(false, intMax));

	int answer = 0;
	
	for (const vector<int>& road : roads)
	{
		LinkVillage(road);
	}

	DFS(1, 0, K);

	for (int i = 1; i < visited.size(); ++i)
	{
		if (visited[i].first == true)
		{
			++answer;
		}
	}

	return answer;
}

/*
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

enum { START, DEST, COST };

struct QueueData
{
	int nowPos;
	int nowCost;
};

struct Node
{
	void Insert(int dest, int cost)
	{
		if (edges.find(dest) != edges.end() && edges[dest] <= cost)
		{
			return;
		}
		edges[dest] = cost;
	}

	vector<QueueData> ConvertQueueData(int nowCost)
	{
		vector<QueueData> queueData;

		for (auto edge : edges)
		{
			queueData.emplace_back(QueueData{ edge.first, nowCost + edge.second });
		}

		return queueData;
	}

	map<int, int> edges;
};

void InsertQueueData(queue<QueueData>& queueData, vector<Node>& graph, const int nowPos, const int cost)
{
	vector<QueueData> convertedData = graph[nowPos].ConvertQueueData(cost);
	for (QueueData& q : convertedData)
	{
		queueData.push(q);
	}
}

int solution(int N, vector<vector<int> > road, int K) {
	vector<bool> visited(N, false);
	vector<int> costs(N, 500001);
	vector<Node> graph(N);

	queue<QueueData> queueData;

	for (vector<int>& vi : road)
	{
		graph[vi[START] - 1].Insert(vi[DEST] - 1, vi[COST]);
		graph[vi[DEST] - 1].Insert(vi[START] - 1, vi[COST]);
	}
	InsertQueueData(queueData, graph, 0, 0);
	visited[0] = true;

	while (!queueData.empty())
	{
		QueueData data = queueData.front();
		queueData.pop();

		if (costs[data.nowPos] <= data.nowCost || data.nowCost > K)
		{
			continue;
		}

		costs[data.nowPos] = data.nowCost;
		visited[data.nowPos] = true;
		InsertQueueData(queueData, graph, data.nowPos, data.nowCost);
	}

	return count(visited.begin(), visited.end(), true);
}
*/