#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<pair<int, int>>map[201];


int dijkstra(int start,int dest) {
    if (start == dest)return 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    int dist[201];
    pq.push({ 0,start });
    for (int i = 0; i < 201; i++)
        dist[i] = 1e9;
    dist[start] = 0;
    while (!pq.empty()) {
        int val = pq.top().first;
        int here = pq.top().second;
        pq.pop();
        for (int i = 0; i < map[here].size(); i++) {
            int next = map[here][i].first;
            int cost = map[here][i].second;
            if (dist[next] > cost + val) {
                dist[next] = cost + val;
                pq.push({ cost + val,next });
            }
        }
    }
    return dist[dest];
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    int adj[201][201];
    for (int i = 0; i < 201; i++)
        for (int j = 0; j < 201; j++)
            adj[i][j] = 1e9;

    for (int i = 0; i < fares.size(); i++) {
        adj[fares[i][0]][fares[i][1]]=fares[i][2];
        adj[fares[i][1]][fares[i][0]] = fares[i][2];
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <=n; k++) {
                adj[j][k] = min(adj[j][k], adj[j][i], adj[i][k]);
            }
        }
    }
    answer = 1e9;
    for (int i = 1; i <= n; i++) {
        answer = min(answer, adj[s][i] + adj[i][a] + adj[i][b]);
    }

    ///다익스트라는 효율성에서 탈락
   /* for (int i = 0; i < fares.size(); i++) {
        map[fares[i][0]].push_back({ fares[i][1],fares[i][2] });
        map[fares[i][1]].push_back({ fares[i][0],fares[i][2] });
    }

    answer = dijkstra(s, a) + dijkstra(s, b);
    for (int i = 1; i <= n; i++) {
        int si = dijkstra(s, i);
        int ia = dijkstra(i, a);
        int ib = dijkstra(i, b);
        if (si == 1e9 || ia == 1e9 || ib == 1e9)
            continue;
        answer = min(answer, dijkstra(s, i) + dijkstra(i, a) + dijkstra(i, b));
    }*/

    return answer;
}
int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    vector<vector<int>>vec({ { 4, 1, 10 }, { 3, 5, 24 }, { 5, 6, 2 }, { 3, 1, 41 }, { 5, 1, 24 }, { 4, 6, 50 }, { 2, 4, 66 }, { 2, 3, 22 }, { 1, 6, 25 } });
    solution(6, 4, 6, 2, vec);
    return 0;
}