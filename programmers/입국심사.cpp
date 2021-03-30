#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    long long low = 1;
    long long high = times[times.size() - 1] * (long long)n;

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long cnt = 0;
        for (int i = 0; i < times.size(); i++) {
            cnt += mid / times[i];
        }
        if (cnt < n) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}


int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    solution(6, vector<int>({ 7,10 }));
    return 0;
}