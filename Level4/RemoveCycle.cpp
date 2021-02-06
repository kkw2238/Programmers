
/*
	n개의 노드로 구성된 그래프에서 하나의 노드만을 제거해서 사이클이 없도록 만들고 싶습니다.

	노드의 개수 n, 노드간의 연결 edges가 매개변수로 주어질 때, 노드를 딱 하나 제거해서 그래프를 사이클이 없도록 만들 수 있다면 해당 노드의 번호를 return 하도록 solution 함수를 완성하세요.
	단, 그런 노드가 없다면 0을 return하고, 여러 개라면 노드의 번호의 합을 return하세요.

	제한사항

		노드 번호는 1 부터 시작합니다.
		주어진 그래프에 반드시 하나 이상의 사이클은 있습니다.
		노드간의 연결에는 방향이 없습니다.
		주어지는 노드의 수는 2개 이상 5,000개 이하입니다.
		연결의 수는 1개 이상 n(n + 1)/2개 이하입니다.
*/

#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;
using Edge = vector<int>;

struct Node {
	vector<int> likedNode;
};

struct Leaf {
	vector<int> parents;
	vector<int> children;

	int tier = -1;
};

class Graph {
public:
	Graph(int n, const vector<Edge>& edges) :
		nodeCount(n),
		nodes(vector<Node>(n))
	{
		for (Edge e : edges) {
			nodes[e[0] - 1].likedNode.push_back(e[1] - 1);
			nodes[e[1] - 1].likedNode.push_back(e[0] - 1);
		}
	}
public:
	vector<Node> nodes;
	int nodeCount = 0;
};

class Tree {
public:
	Tree(int n) : nodeCount(n), leaves(vector<Leaf>(n)) {}

public:
	void MakeRelation(const int parent, const int child) {
		leaves[child].parents.push_back(parent);
		leaves[parent].children.push_back(child);

		if (leaves[child].parents.size() > 1) originhadMultiParent.insert(child);
	}

	void LinkBetweenLeaves(const int to, const int from) {
		if (leaves[to].tier > leaves[from].tier) MakeRelation(to, from);
		else  MakeRelation(from, to);
	}

	void GenerationTree(const Graph& g) {
		for (int start = 0; start < nodeCount; ++start) {
			if (leaves[start].tier != -1) continue;
			vector<vector<int>> usedEdge(nodeCount, vector<int>(nodeCount, 0));
			queue<pair<int, int>> nextNodeNTier;

			nextNodeNTier.emplace(start, 0);

			while (!nextNodeNTier.empty()) {
				pair<int, int> fromNTier = nextNodeNTier.front();
				nextNodeNTier.pop();
				leaves[fromNTier.first].tier = fromNTier.second;

				for (int to : g.nodes[fromNTier.first].likedNode) {
					if (usedEdge[to][fromNTier.first] == 0 && usedEdge[fromNTier.first][to] == 0) {
						usedEdge[to][fromNTier.first] = 1; usedEdge[fromNTier.first][to] = 1;
						nextNodeNTier.emplace(to, fromNTier.second + 1);

						LinkBetweenLeaves(to, fromNTier.first);
					}
				}
			}
		}
	}

	bool ExceptedNumber(int parent) {
		set<int> hadMultiParent = originhadMultiParent;
		hadMultiParent.erase(parent);

		for (int i : leaves[parent].children) {
			if (leaves[i].parents.size() > 2) return false;
			else if (leaves[i].parents.size() - 1 == 1)
				hadMultiParent.erase(i);
		}

		return hadMultiParent.empty();
	}

	int FindCanMakeSpanningTree() {
		int result = 0;
		set<int> alreadyExceptedParent;

		for (int i : originhadMultiParent) {
			for (int p : leaves[i].parents) {
				if (alreadyExceptedParent.find(p) != alreadyExceptedParent.end()) continue;
				alreadyExceptedParent.insert(p);

				if (ExceptedNumber(p))
					result += (p + 1);
			}
		}

		return result;
	}

public:
	int nodeCount = 0;
	set<int> originhadMultiParent;
	vector<Leaf> leaves;
};


int solution(int n, vector<vector<int>> edges) {
	Graph graph(n, edges);
	Tree tree(n);

	tree.GenerationTree(graph);

	return tree.FindCanMakeSpanningTree();
}