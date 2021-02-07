#include<vector>
#include <queue>
using namespace std;
struct node {
    int x;
    int y;
    int cnt;
};
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
queue<node>q;
int n, m;
int bfs(vector<vector<int>>map) {
    vector<vector<bool>>chk;
    for (int i = 0; i < map.size(); i++) {
        vector<bool> chkChild;
        for (int j = 0; j < map[i].size(); j++) {
            chkChild.push_back(false);
        }
        chk.push_back(chkChild);
    }
    q.push({ 0,0,0 });
    chk[0][0] = true;
    while (!q.empty()) {
        int tx = q.front().x;
        int ty = q.front().y;
        int tcnt = q.front().cnt;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + tx;
            int ny = dy[i] + ty;
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
            if (chk[nx][ny])continue;
            if (map[nx][ny] == 0)continue;

            if (nx == n - 1 && ny == m - 1) {
                return tcnt + 1;
            }
            chk[nx][ny] = true;
            q.push({ nx,ny,tcnt + 1 });
        }
    }

    return -1;
}
int solution(vector<vector<int> > maps)
{
    n = maps.size();
    m = maps[0].size();
    int answer = bfs(maps);
    return answer;
}