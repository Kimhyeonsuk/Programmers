#include <string>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int, vector<int>, less<int>>pq;

    for (int i = 0; i < works.size(); i++) {
        pq.push(works[i]);
    }

    while (n != 0&&!pq.empty()) {
        int num = pq.top();
        pq.pop();
        if (num > 0) {
            pq.push(num - 1);
        }
        n--;
    }

    while (!pq.empty()) {
        answer += pow(pq.top(), 2);
        pq.pop();
    }
    return answer;
}