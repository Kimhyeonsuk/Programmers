#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool comp(pair<int, pair<int, bool>>a, pair<int, pair<int, bool>>b) {
    return a.first < b.first;
}
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector < pair<int, pair<int, bool>>>allStudent;
    for (int i = 0; i < lost.size(); i++) {
        allStudent.push_back({lost[i], { i,false }});
    }
    for (int i = 0; i < reserve.size(); i++) {
        allStudent.push_back({ reserve[i],{i,true} });
    }

    sort(allStudent.begin(), allStudent.end(), comp);

    answer = reserve.size();
    int i = 0;
    while(i<allStudent.size()){
    
        if (allStudent[i].second.second == false) {
            if (i != 0 && (i != allStudent.size() - 1) && allStudent[i + 1].second.second) {
                allStudent[i + 1].second.second = false;
                answer++;
                i += 2;
            }
            else if (i != 0 && (i != allStudent.size() - 1) && allStudent[i -1].second.second) {
                allStudent[i - 1].second.second = false;
                answer++;
                i++;
            }
            else if (i == 0 && allStudent[i + 1].second.second) {
                allStudent[i + 1].second.second = false;
                answer++;
                i += 2;
            }
            else if (i == allStudent.size() - 1 && allStudent[i - 1].second.second) {
                answer++;
                i++;
            }
        }
        i++;
    }
    return answer;
}
int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    return 0;
}