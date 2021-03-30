#include <string>
#include <vector>
#include <queue>
using namespace std;

int bfs(int startNum,int n,vector<vector<int>>& vec) {
    vector<bool>chk(n + 1);
    chk[startNum] = true;
    queue<int>q;
    q.push(startNum);

    int cnt = 0;
    while (!q.empty()) {
        int num = q.front();
        q.pop();
        for (int i = 0; i < vec[num].size(); i++) {
            if (chk[vec[num][i]])continue;
            chk[vec[num][i]] = true;
            q.push(vec[num][i]);
            cnt++;
        }
    }
    return cnt;
}
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>>win(n + 1);
    vector<vector<int>>defeat(n + 1);

    for (int i = 0; i < results.size(); i++) {
        win[results[i][0]].push_back(results[i][1]);
        defeat[results[i][1]].push_back(results[i][0]);
    }

    for (int i = 1; i <= n; i++) {
        int winNum = bfs(i, n, win);
        int defeatNum = bfs(i, n, defeat);
        int totalNum = winNum + defeatNum;
        if (totalNum == n - 1) {
            answer++;
        }
    }
    return answer;
}