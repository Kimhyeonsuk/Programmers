#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>>dp;
    for (int i = 0; i < triangle.size(); i++) {
        dp.push_back(vector<int>(triangle[i].size(), 0));
    }

    dp[0][0] = triangle[0][0];
    for (int i = 0; i < triangle.size()-1; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            int curval = dp[i][j];
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + triangle[i + 1][j]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + triangle[i + 1][j + 1]);
            answer = max(answer, dp[i + 1][j]);
            answer = max(answer, dp[i + 1][j + 1]);
        }
    }
    return answer;
}
int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    return 0;
}