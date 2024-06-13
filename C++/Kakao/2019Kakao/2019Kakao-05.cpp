/*
#include <string>
#include <vector>
#include <set>

using namespace std;
const int PILLAR_BOTTOM = 0, BEAM = 1;

const bool CanBuildBeam(const vector<vector<int>>& builded_frame, const int x, const int y) {
	bool result = false;
	if (x > 0) result = builded_frame[x - 1][y] == BEAM;
	if (y > 0) result = result || builded_frame[x][y - 1] == PILLAR_BOTTOM || builded_frame[x + 1][y - 1] == PILLAR_BOTTOM;
	return result;
}

bool CanBuildPiilar(const vector<vector<int>>& builded_frame, const int x, const int y) {
	bool result = false;

	if (x > 0) result = builded_frame[x - 1][y] == BEAM;
	if (y > 0) result = result || builded_frame[x][y - 1] == PILLAR_BOTTOM;
	else return true;

	return result;
}

void InstallFrame(vector<vector<int>>& frame, const int xpos, const int ypos, const int type) {
	if (type == PILLAR_BOTTOM) frame[xpos][ypos] = CanBuildPiilar(frame, xpos, ypos) ? type : frame[xpos][ypos];
	else frame[xpos][ypos] = CanBuildBeam(frame, xpos, ypos) ? type : frame[xpos][ypos];
}

bool IsEnableEraseFrame(vector<vector<int>>& frame, const int xpos, const int ypos) {
	bool result = true;

	if (frame[xpos][ypos] == PILLAR_BOTTOM) {
		if(!CanBuildPiilar(frame, xpos, ypos)) return false;
		return IsEnableEraseFrame(frame, xpos, ypos + 1);
	}
	else if (frame[xpos][ypos] == BEAM) {
		if (!CanBuildBeam(frame, xpos, ypos)) return false;
		return IsEnableEraseFrame(frame, xpos + 1, ypos);
	}

	return false;
}

vector<vector<int>> init(const int n, const vector<vector<int>>& build_frame) {
	enum { XPos, YPos, Type, IsInstall};

	vector<vector<int>> result(n, vector<int>(n, -1));
	for (const vector<int> vi : build_frame) {
		const int xpos = vi[XPos], ypos = vi[YPos];
		if (vi[IsInstall] == 1)
			InstallFrame(result, xpos, ypos, vi[Type]);

		else {
			int type = result[xpos][ypos];
			result[xpos][ypos] = -1;

			if(!IsEnableEraseFrame(result, type == BEAM ? xpos + 1 : xpos, type == PILLAR_BOTTOM ? ypos + 1 : ypos)) result[xpos][ypos] = type;
		}

		cout << "COMMAND" << endl;
		cout << vi;
		for (vector<int>& vi : result) {
			cout << vi;
		}
		cout << endl;
	}

	return result;
}

vector<vector<int>> LinkedFrame(const vector<vector<int>>& installed_frame, const int xpos,const int ypos) {
	vector<vector<int>> result;


	return result;
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer = init(n + 1, build_frame);


	return answer;
}

}*/