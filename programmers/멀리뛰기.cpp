#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<int>vec(n+1, 0);
    vec[0] = 1;
    vec[1] = 1;

    for (int i = 2; i <= n; i++) {
        vec[i] = (vec[i - 1] + vec[i - 2]) % 1234567;
    }
    answer = vec[n];
    return answer;
}