/*
	https://programmers.co.kr/learn/courses/30/lessons/49189
*/
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

using PNC = pair<int, int>;

struct Compare {
	bool operator()(const PNC& a, const PNC& b) {
		return a.second > b.second;
	}
};

struct Node {
	vector<int> nextNode;
	bool visited = false;
	int distance = -1;
};

class Graph {
public:
	Graph(int count) { nodes.resize(count); }

public:
	void InsertEdges(int start, int end) {
		nodes[start - 1].nextNode.push_back(end - 1);
		nodes[end - 1].nextNode.push_back(start - 1);
	}

	void CalculateDistance(int start, int distance) {
		nodes[start].visited = true;

		if (nodes[start].distance > distance || nodes[start].distance == -1)
			nodes[start].distance = distance;


	}

	int GetFarNodes() {
		priority_queue<PNC, vector<PNC>, Compare> foundNodes;
		int maxDistance = 0, maxDistanceCount = 0;

		foundNodes.emplace(0, 0);
		nodes[0].visited = true;

		while (!foundNodes.empty()) {
			PNC nowInfo = foundNodes.top();
			foundNodes.pop();

			if (nowInfo.second > maxDistance) {
				maxDistance = nowInfo.second;
				maxDistanceCount = 1;
			}
			else if (nowInfo.second == maxDistance)
				++maxDistanceCount;

			for (int nextNode : nodes[nowInfo.first].nextNode) {
				if (!nodes[nextNode].visited) {
					foundNodes.emplace(nextNode, nowInfo.second + 1);
					nodes[nextNode].visited = true;
				}
			}
		}
		return maxDistanceCount;
	}
public:
	vector<Node> nodes;
};

int solution(int n, vector<vector<int>> edge) {
	Graph graph(n);

	for (vector<int>& ed : edge)
		graph.InsertEdges(ed[0], ed[1]);

	return graph.GetFarNodes();
}