#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int>vec(n+1);
    vec[0] = 1;
    vec[1] = 1;
    for (int i = 2; i <= n; i++) {
        vec[i] = (vec[i - 1] + vec[i - 2])%1000000007;
        answer = max(answer, vec[i]);
    }
    return answer;
}
int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    return 0;
}