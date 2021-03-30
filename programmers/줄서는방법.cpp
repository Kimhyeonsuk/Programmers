#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

long long factorial(int n) {
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}
vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int>vec;
    for (int i = 1; i <= n; i++) {
        vec.push_back(i);
    }
    while (1) {
        if (n == 0)
            break;
        long long slice = factorial(n) / n;
        long long idx = int((k-1)/ slice);
        answer.push_back(vec[idx]);
        vec.erase(vec.begin() + idx);
        n--;
        k %= slice;
        if (k == 0) {
            k = slice;
        }
    }
    return answer;
}


//vector<int> solution(int n, long long k) {
//    vector<int> answer;
//    vector<int>vec;
//    for (int i = 1; i <= n; i++) {
//        vec.push_back(i);
//    }
//
//    long long cnt = 1;
//    do
//    {
//        if (cnt == k) {
//            for (int i = 0; i < n; i++) {
//                answer.push_back(vec[i]);
//            }
//            break;
//        }
//        cnt++;
//        
//    } while (next_permutation(vec.begin(), vec.end()));
//    return answer;
//}