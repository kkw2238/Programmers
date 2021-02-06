/*
	https://programmers.co.kr/learn/courses/30/lessons/49191
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	vector<int> losePlayer;
	vector<int> winPlayer;
};

class Graph {
public:
	Graph(int n, const vector<vector<int>>& results) :
		playerCount(n),
		players(vector<Node>(n))
	{
		for (vector<int> result : results) {
			players[result[1] - 1].losePlayer.push_back(result[0] - 1);
			players[result[0] - 1].winPlayer.push_back(result[1] - 1);
		}
	}

public:
	size_t FindUpside(int playerNum) {
		vector<int> visited(playerCount, 0);
		queue<int> willVisit;
		size_t visitCount = 0;

		willVisit.push(playerNum);

		while (!willVisit.empty()) {
			int now = willVisit.front();
			willVisit.pop();

			for (int next : players[now].losePlayer) {
				if (visited[next] != 1) {
					visited[next] = 1;
					willVisit.push(next);
					++visitCount;
				}
			}
		}

		return visitCount;
	}
	size_t FindDownside(int playerNum) {
		vector<int> visited(playerCount, 0);
		queue<int> willVisit;
		size_t visitCount = 0;

		willVisit.push(playerNum);
		visited[playerNum] = 1;

		while (!willVisit.empty()) {
			int now = willVisit.front();
			willVisit.pop();

			for (int next : players[now].winPlayer) {
				if (visited[next] != 1) {
					visited[next] = 1;
					willVisit.push(next);
					++visitCount;
				}
			}
		}

		return visitCount;
	}

	int FindConfirmationPlayer() {
		int result = 0;
		for (int i = 0; i < playerCount; ++i) {
			size_t visitedPlayerCount = FindDownside(i) + FindUpside(i);

			if (visitedPlayerCount == playerCount - 1)	++result;
		}

		return result;
	}

public:
	int playerCount = 0;
	vector<Node> players;
};

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	Graph graph(n, results);

	return graph.FindConfirmationPlayer();
}