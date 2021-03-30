//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//using namespace std;
//
//int solution(vector<int> stones, int k) {
//    int answer = 0;
//    int stoneNum = stones.size();
//    vector<int>window;
//    int minNum = 0;
//    for (int i = 0; i < k; i++) {
//        window.push_back(stones[i]);
//        minNum = max(minNum, stones[i]);
//    }
//
//    int idx = 1;
//    while (idx <= stoneNum - k) {
//        window.erase(window.begin());
//        window.push_back(stones[idx + k - 1]);
//        int n = 0;
//        for (int i = 0; i < window.size(); i++) {
//            n = max(n, window[i]);
//        }
//        minNum = min(minNum, n);
//        idx++;
//    }
//    return minNum;
//}
//int main() {
//    solution({ 2,4,5,3,2,1,4,2,5,1 },3);
//    return 0;
//}

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool chk(int mid, int k, vector<int>& stones) {
    int cnt = 0;
    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] - mid <= 0) {
            cnt++;
        }
        else {
            cnt = 0;
        }

        if (cnt >= k)
            return true;
    }

    return false;
}
int solution(vector<int> stones, int k) {
    int answer = 0;
    int low = 1;
    int high = *max_element(stones.begin(), stones.end());
    while (low <= high) {
        int mid = (low + high) / 2;
        if (chk(mid, k, stones)) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}