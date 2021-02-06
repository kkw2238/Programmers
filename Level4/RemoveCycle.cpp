
/*
	n���� ���� ������ �׷������� �ϳ��� ��常�� �����ؼ� ����Ŭ�� ������ ����� �ͽ��ϴ�.

	����� ���� n, ��尣�� ���� edges�� �Ű������� �־��� ��, ��带 �� �ϳ� �����ؼ� �׷����� ����Ŭ�� ������ ���� �� �ִٸ� �ش� ����� ��ȣ�� return �ϵ��� solution �Լ��� �ϼ��ϼ���.
	��, �׷� ��尡 ���ٸ� 0�� return�ϰ�, ���� ����� ����� ��ȣ�� ���� return�ϼ���.

	���ѻ���

		��� ��ȣ�� 1 ���� �����մϴ�.
		�־��� �׷����� �ݵ�� �ϳ� �̻��� ����Ŭ�� �ֽ��ϴ�.
		��尣�� ���ῡ�� ������ �����ϴ�.
		�־����� ����� ���� 2�� �̻� 5,000�� �����Դϴ�.
		������ ���� 1�� �̻� n(n + 1)/2�� �����Դϴ�.
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