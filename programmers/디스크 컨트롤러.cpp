#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>pq;
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int finTime = 0;
    sort(jobs.begin(), jobs.end());
    int i = 0;
    while (i < jobs.size() || !pq.empty()) {
        if (i<jobs.size() && finTime>=jobs[i][0]) {
            pq.push({ jobs[i][1],jobs[i][0] });
            i++;
            continue;
        }
        

        if (!pq.empty()) {
            finTime += pq.top().first;
            answer += finTime - pq.top().second;
            pq.pop();
        }
        else
            finTime = jobs[i][0];
    }
  
    return answer/jobs.size();
}
int main() {
    solution(vector<vector<int>>({ {0, 3} ,{4, 4},{5, 3},{4, 1} }));
    return 0;
}