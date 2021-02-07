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
    queue<pair<int, int>>q;//�߿䵵, loc ���� ������ ������ ����
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
        if (document.first < pq.top()) {//���õ� ������ �߿䵵���� ���� ������ �����Ҷ�
            q.push(document);
        }
        else {//���õ� ������ ���� ���� �߿䵵�� ���� �����϶� ����Ѵ�
            pq.pop();
            cnt++;
            //����� ������ ó�� ã���ִ� ������ ��� fnd�� true�� �ٲٰ� ����
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