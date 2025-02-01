#include <string>
#include <vector>
#include <stack>

#include <iostream>

using namespace std;

string solution(string message)
{
	string answer = "";

	stack<int> indices;
	indices.push(0);

	while (!indices.empty())
	{
		int index = indices.top();
		indices.pop();

		if (index >= message.length())
		{
			continue;
		}

		answer = message[index] + answer;
		indices.push(index * 2 + 1);
		indices.push(index * 2 + 2);
	}

	return answer;
}

int main()
{
	solution("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}