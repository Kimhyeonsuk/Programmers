#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int bfs(int n,vector<vector<int>>&vec,vector<vector<int>>&res) {
    vector<bool>chk(n + 1,false);
    queue<pair<int,int>>q;
    chk[1] = true;
    q.push({ 1,0 });

    int maxNum = 0;
    while (!q.empty()) {
        int num = q.front().first;
        int cnt = q.front().second;
        q.pop();
        for (int i = 0; i < vec[num].size(); i++) {
            if (chk[vec[num][i]])continue;
            chk[vec[num][i]] = true;
            q.push({ vec[num][i], cnt + 1 });
            res[cnt + 1].push_back(vec[num][i]);
            maxNum = max(maxNum, cnt + 1);
        }
    }
    return res[maxNum].size();
    
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>>vec(n + 1);
    vector<vector<int>>res(n + 1);
    for (int i = 0; i < edge.size(); i++) {
        vec[edge[i][0]].push_back(edge[i][1]);
        vec[edge[i][1]].push_back(edge[i][0]);
    }
    answer = bfs(n, vec, res);
    return answer;
}