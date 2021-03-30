#include <string>
#include <vector>

using namespace std;
void move(int n,int from ,int temp,int to,vector<vector<int>>&vec) {
    if (n == 1) {
        vec.push_back({from, to});
        return;
    }
    else {
        move(n - 1, from, to, temp, vec);
        vec.push_back({ from,to });
        move(n - 1, temp, from, to, vec);
    }
}
vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    move(n, 1, 2, 3, answer);
    return answer;
}