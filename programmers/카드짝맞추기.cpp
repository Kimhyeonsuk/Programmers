#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

vector<bool>Select(7, false);
vector<int> cardList;
vector<pair<int, int>>cardMap[7];
vector<int>cardOrder;
vector<int>sameCardOrder;
int answer;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void checkCard(vector<vector<int>>board) {
    vector<bool> chk(7,  false);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] != 0) {
                if (chk[board[i][j]])continue;
                chk[board[i][j]] = true;
                cardList.push_back(board[i][j]);
            }
        }
    }
}
void saveCardLoc(vector<vector<int>>board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] != 0) {
                cardMap[board[i][j]].push_back({ i,j });
            }
        }
    }
}
int solve(int r,int c, int cnt, int cardNum,int idx,vector<vector<int>>MAP) {
    if (cnt == 2) return 0;

    queue<pair<pair<int, int>, int>> Q;
    vector<vector<bool>> Visit(MAP.size(), vector<bool>(MAP.size(), false));
    Q.push(make_pair(make_pair(r,c), 0));
    Visit[r][c] = true;

    int Ex, Ey;
    if (cnt == 0)
    {
        Ex = cardMap[cardNum][idx].first;
        Ey = cardMap[cardNum][idx].second;
    }
    else
    {
        Ex = cardMap[cardNum][!idx].first;
        Ey = cardMap[cardNum][!idx].second;
    }

    while (Q.empty() == 0)
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int Cnt = Q.front().second;
        Q.pop();

        if (x == Ex && y == Ey)
        {
            MAP[x][y] = 0;
            Cnt += solve(x, y, cnt + 1, cardNum, idx, MAP);
            return Cnt;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < 7 && ny < 7)
            {
                if (Visit[nx][ny] == false)
                {
                    Visit[nx][ny] = true;
                    Q.push(make_pair(make_pair(nx, ny), Cnt + 1));
                }
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            while (1)
            {
                if (nx < 0 || ny < 0 || nx >= 7 || ny >= 7)
                {
                    nx -= dx[i];
                    ny -= dy[i];
                    break;
                }
                if (MAP[nx][ny] != 0) break;
                nx += dx[i];
                ny += dy[i];
            }

            if (Visit[nx][ny] == false)
            {
                Visit[nx][ny] = true;
                Q.push(make_pair(make_pair(nx, ny), Cnt + 1));
            }
        }
    }
}
void setSameCardSequence(int cnt, vector<vector<int>>board, int r, int c) {
    if (cnt == cardList.size()) {
        int result = 0;
        for (int i = 0; i < cardList.size(); i++) {
            int cardNum = cardOrder[i];
            int idx = sameCardOrder[i];
            vector<vector<int>>MAP = board;
            result+=solve(0,r, c, cardNum, idx,MAP);
            r = cardMap[cardNum][idx].first;
            c = cardMap[cardNum][idx].second;
        }
        answer = min(answer, result);
        return;
    }

    for (int i = 0; i < 2; i++) {
        sameCardOrder.push_back(i);
        setSameCardSequence(cnt + 1, board, r, c);
        sameCardOrder.pop_back();
    }
}
void setCardSequence(int cnt, vector<vector<int>>board, int r, int c) {
    if (cnt == cardList.size()) {
        setSameCardSequence(0,board,r,c);
    }

    for (int i = 0; i < cardList.size(); i++) {
        int cardNum = cardList[i];
        if (Select[cardNum])continue;
        Select[cardNum] = true;
        cardOrder.push_back(cardNum);
        setCardSequence(cnt + 1,board,r,c);
        cardOrder.pop_back();
        Select[cardNum] = false;
    }

}
int solution(vector<vector<int>> board, int r, int c) {
    answer = 1e9;
    checkCard(board);
    saveCardLoc(board);
    setCardSequence(0, board, r, c);
    return answer;
}
int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    return 0;
}