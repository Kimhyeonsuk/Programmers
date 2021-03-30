//#include <string>
//#include <vector>
//#include <iostream>
//using namespace std;
//
//int dx[2] = { 0,1 };
//int dy[2] = { 1,0 };
//int dist = 1e9;
//int res = 0;
//void dfs(int x,int y,int m,int n,int cnt,vector<vector<int>>&vec,vector<vector<bool>>&chk) {
//    if (x == n && y == m) {
//        if (cnt < dist) {
//            res = 1;
//            dist = cnt;
//        }
//        else if (cnt == dist) {
//            res++;
//        }
//        return;
//    }
//    else {
//        for (int i = 0; i < 2; i++)
//        {
//            int nx = x + dx[i];
//            int ny = y + dy[i];
//            if (nx <= 0 || ny <= 0 || nx > n || ny > m)continue;
//            if (chk[nx][ny])continue;
//            if (vec[nx][ny] == 1)continue;
//            chk[nx][ny] = true;
//            dfs(nx, ny, m, n, cnt + 1, vec, chk);
//            chk[nx][ny] = false;
//        }
//    }
//}
//int solution(int m, int n, vector<vector<int>> puddles) {
//    int answer = 0;
//    vector<vector<int>>vec(n + 1, vector<int>(m + 1, 0));
//    vector<vector<bool>>chk(n + 1, vector<bool>(m + 1, false));
//    for (int i = 0; i < puddles.size(); i++) {
//        vec[puddles[i][1]][puddles[i][0]] = 1;
//    }
//    chk[1][1] = true;
//    dfs(1,1,m, n, 0, vec,chk);
//    answer = res;
//    return answer;
//}
//int main() {
//    solution(4, 3, { { 2,2 } });
//    return 0;
//}

//#include <string>
//#include <vector>
//#include <iostream>
//using namespace std;
//
//int dx[2] = { 1,0 };
//int dy[2] = { 0,1 };
//bool chk(int x, int y, vector<vector<int>>& puddles) {
//    for (int i = 0; i < puddles.size(); i++) {
//        if (x == puddles[i][0] && y == puddles[i][1])
//            return false;
//    }
//    return true;
//}
//int res = 0;
//void solve(int m,int n,int x, int y, int cnt,vector<vector<int>>& puddles) {
//    if (x == m && y == n) {
//        res++;
//        return;
//    }
//    for (int i = 0; i < 2; i++) {
//        int nx = x + dx[i];
//        int ny = y + dy[i];
//
//        if (nx > m || ny > n)continue;
//        if (!chk(nx, ny, puddles))continue;
//        solve(m, n, nx, ny, cnt + 1, puddles);
//    }
//}
//int solution(int m, int n, vector<vector<int>> puddles) {
//    int answer = 0;
//    solve(m, n, 1, 1, 0, puddles);
//    answer = res;
//    return answer;
//}
//int main() {
//    solution(4, 3,{ {2,2} });
//    return 0;
//}

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>>vec(101, vector<int>(101, 1));
    for (int i = 0; i < puddles.size(); i++) {
        vec[puddles[i][1]][puddles[i][0]] = 0;
        if (puddles[i][1] == 1) {
            for (int j = puddles[i][0]; j <= m; j++) {
                vec[1][j] = 0;
            }
        }
        else if (puddles[i][0] == 1) {
            for (int j = puddles[i][1]; j <= n; j++) {
                vec[j][1] = 0;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if (vec[i][j]==0)continue;
            vec[i][j] = (vec[i - 1][j] + vec[i][j - 1]) % 1000000007;
        }
    }
    answer = vec[n][m];
    return answer;
}
int main() {
    solution(4, 3, { {} });
    return 0;
}