#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	for (int i = 0; i < commands.size(); i++) {
		int inum = commands[i][0];
		int jnum = commands[i][1];
		int knum = commands[i][2];

		vector<int>vec;
		for (int j = inum - 1; j <= jnum - 1; j++) {
			vec.push_back(array[j]);
		}
		sort(vec.begin(), vec.end());
		answer.push_back(vec[knum - 1]);
	}
	return answer;
}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	return 0;
}