#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int>s;

    for (int i = 0; i < moves.size(); i++) {
        int loc = moves[i]-1;
        for (int j = 0; j < board.size(); j++) {
            if (board[j][loc] != 0) {//인형이 존재할 때
                if (!s.empty() && s.top() == board[j][loc]) {
                    s.pop();
                    answer+=2;
                }
                else {
                    s.push(board[j][loc]);
                }
                board[j][loc] = 0;
                break;
            }
        }
    }
    return answer;
}

int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    return 0;
}
