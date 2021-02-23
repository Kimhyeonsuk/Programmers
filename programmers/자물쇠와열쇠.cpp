#include <string>
#include <vector>
#include <iostream>

using namespace std;
int keySize, lockSize, boardSize;
void rotateKey(vector<vector<int>>& key) {

    vector<vector<int>>tmp(keySize, vector<int>(keySize,0));
    for (int j = keySize - 1; j >= 0; j--) {
        for (int i = 0; i < keySize; i++) {
            tmp[i][j] = key[keySize - j - 1][i];
        }
    }

    key = tmp;
}
bool putKey(int x, int y, vector<vector<int>>key, vector<vector<int>>board) {
    for (int i = x; i <x+ keySize; i++) {
        for (int j = y; j < y + keySize; j++) {
            board[i][j] += key[i - x][i - y];
        }
    }

    //좌물쇠 부분 확인
    for (int i = keySize - 1; i <= boardSize - keySize; i++) {
        for (int j = keySize - 1; j <= boardSize - keySize; j++) {
            if (board[i][j] == 1) continue;
            //1이 아니라면 바로 false를 리턴
            return false;
        }
    }


    return true;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    keySize = key.size();
    lockSize = lock.size();
    boardSize = lockSize + (keySize - 1) * 2;

    vector<vector<int>>board(boardSize, vector<int>(boardSize, 0));
    for (int i = keySize-1; i <= boardSize-keySize; i++) {
        for (int j = keySize-1; j <= boardSize-keySize; j++) {
            board[i][j] = lock[i + 1 - keySize][j + 1 - keySize];
        }
    }

    for (int k = 0; k < 4; k++) {
        for (int i = 0; i <= boardSize - keySize; i++) {
            for (int j = 0; j <= boardSize - keySize; j++) {
                if (putKey(i,j,key,board)) {
                    return true;
                }
            }
        }

        rotateKey(key);
    }

    return false;
}
int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    return 0;
}