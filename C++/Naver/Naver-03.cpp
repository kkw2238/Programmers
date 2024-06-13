
#include <string>
#include <vector>
#include <memory>
#include <set>

using namespace std;

class Node {
public:
	Node() {};
	~Node() {};

public:
	const bool Initialized() { return myIndex != -1; }
	void Initialize(shared_ptr<Node> beforeNode) {
		before_Node.push_back(beforeNode);
	}

	void GetBeforeCount(set<int>& beforeIndex) {
		beforeIndex.insert(myIndex);

		for (int i = 0; i < before_Node.size(); ++i) {
			before_Node[i]->GetBeforeCount(beforeIndex);
		}
	}
public:
	int myIndex = -1;
	int myTime = 0;
	vector<shared_ptr<Node>> before_Node;
};

class Map {
public:
	Map(vector<int>& cooktime) {
		nodes.resize(cooktime.size());

		for (int i = 0; i < cooktime.size(); ++i) {
			nodes[i].myIndex = i;
			nodes[i].myTime = cooktime[i];
		}
	};

	void AddNode(int index, int beforeIndex) {

		nodes[index].Initialize(make_shared<Node>(nodes[index]));

	}

	int GetBeforeCount(int k) {
		set<int> beforeIndex;
		nodes[k].GetBeforeCount(beforeIndex);

		return beforeIndex.size();
	}
	int GetBeforeTime(int k) {
		return 1;
	}
public:
	vector<Node> nodes;
};


vector<int> solution(vector<int> cook_times, vector<vector<int>> order, int k) {
	vector<int> answer;
	Map map(cook_times);

	for (vector<int>& command : order)
		map.AddNode(command[1] - 1, command[0] - 1);

	answer.push_back(map.GetBeforeCount(k - 1));
	answer.push_back(map.GetBeforeTime(k - 1));
	return answer;
}

int main() {
	vector<int> cook_times = { 5, 30, 15, 30, 35, 20, 4 };
	vector<vector<int>> order = { {2,4},{2,5},{3,4},{3,5},{1,6},{4,6},{5,6},{6,7} };
	int k = 6;
	std::cout << solution(cook_times, order, k);
}