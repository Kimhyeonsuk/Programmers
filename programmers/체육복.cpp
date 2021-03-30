#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    vector<int>allStudent(n + 2, 0);
    for (int i = 0; i < lost.size(); i++) {
        allStudent[lost[i]] += -1;
    }
    for (int i = 0; i < reserve.size(); i++) {
        allStudent[reserve[i]] += 1;
        if (allStudent[reserve[i]] == 0)
            answer++;
    }
    
    for (int i = 1; i <= n; i++) {
        if (allStudent[i]>= 1) {
            if (allStudent[i - 1] == -1) {
                allStudent[i] = 0;
                allStudent[i - 1] = 0;
                answer++;
            }
            else if (allStudent[i + 1] == -1) {
                allStudent[i] = 0;
                allStudent[i + 1] = 0;
                answer++;
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