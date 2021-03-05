#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int bfs(int num,int i,int j,vector<vector<bool>>&chk, vector<vector<int>>&picture,int m,int n) {
    queue<pair<int, int>>q;
    q.push({ i,j });
    chk[i][j] = true;
    int land = 1;
    while (!q.empty()) {
        int tx = q.front().first;
        int ty = q.front().second;

        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = tx + dx[i];
            int ny = ty + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n)continue;
            if (chk[nx][ny])continue;
            if (picture[nx][ny] != num)continue;
            

            chk[nx][ny] = true;
            q.push({ nx,ny });
            land++;
        }
    }

    return land;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<vector<bool>>chk(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++) {
            if (chk[i][j] == false && picture[i][j] != 0) {
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, bfs(picture[i][j],i, j, chk, picture,m,n));
            }
        }
    }


    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    vector<vector<int>>picture({ {1, 1, 1, 0} ,{1, 1, 1, 0},{0, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 1} });
    solution(6, 4, picture);
    return 0;
}