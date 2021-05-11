#include <sstream>
#include <string>
#include <iostream>

using namespace std;
int main()
{
	string s = "  Do  Some thing";
	stringstream ss(s);
	
	while (!ss.eof()) {
		string a;
		ss >> a;

		cout << a;
	}
}