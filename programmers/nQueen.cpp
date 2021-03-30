#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int res = 0;
bool chk(int i,int j,vector<pair<int, int>>& vec) {
    for (int k = 0; k < vec.size(); k++) {
        int x = vec[k].first;
        int y = vec[k].second;
        if (x == i || y == j)return false;
        if (abs(x - i) == abs(y - j))return false;
    }
    return true;
}
void dfs(int n,int cnt,vector<pair<int,int>>&vec) {
    if (cnt == n) {
        res++;
        return;
    }

    for (int j = 0; j < n; j++) {
        if (chk(cnt, j, vec)) {
            vec.push_back({ cnt,j });
            dfs(n, cnt + 1, vec);
            vec.pop_back();
        }
    }
}
int solution(int n) {
    int answer = 0;
    vector < pair<int, int>>vec;
    dfs(n, 0, vec);
    answer = res;
    return answer;
}

int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int n = solution(4);
    return 0;
}