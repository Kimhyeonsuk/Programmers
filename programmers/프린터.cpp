#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int maxPriority = 0;
    priority_queue<int>pq;
    queue<pair<int, int>>q;//중요도, loc 정보 순으로 데이터 저장
    for (int i = 0; i < priorities.size(); i++) {
        q.push({ priorities[i],i });
        maxPriority = max(maxPriority, priorities[i]);
        pq.push(priorities[i]);
    }

    bool fnd = false;
    int cnt = 0;
    while (!fnd) {
        pair<int, int> document = q.front();
        q.pop();
        if (document.first < pq.top()) {//선택된 문서의 중요도보다 높은 문서가 존재할때
            q.push(document);
        }
        else {//선택된 문서가 제일 높은 중요도를 가진 문서일때 출력한다
            pq.pop();
            cnt++;
            //출력한 문서가 처음 찾고있던 문서일 경우 fnd를 true로 바꾸고 종료
            if (document.second == location)
            {
                fnd = true;
                continue;
            }
        }
    }
    return cnt;
}

int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    return 0;
}