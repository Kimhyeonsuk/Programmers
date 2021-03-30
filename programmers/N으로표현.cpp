//#include <string>
//#include <vector>
//#include <algorithm>
//#include <math.h>
//#include <iostream>
//#include <set>
//using namespace std;
//
//int dp[32001];
//int solution(int N, int number) {
//
//	if (N == number)return 1;
//	vector<set<int>> arr(8);
//	for (int i = 0; i < 8; i++) {
//		int n = 0;
//		for (int j = 0; j <= i; j++) {
//			n += N * pow(10, j);
//		}
//		arr[i].insert(n);
//	}
//
//	for (int i = 1; i < 8; i++) {
//		for (int j = 0; j < i; j++) {
//			for (auto& x : arr[j]) {
//				for (auto& y : arr[i - j - 1]) {
//					arr[i].insert(x + y);
//					arr[i].insert(x - y);
//					arr[i].insert(x * y);
//					if (y != 0)arr[i].insert(x / y);
//				}
//			}
//		}
//
//		if (arr[i].find(number) != arr[i].end()) {
//			return i + 1;
//		}
//	}
//	return -1;
//
//}
//int main() {
//	cin.tie(NULL);
//	std::ios::sync_with_stdio(false);
//	solution(4, 4);
//	return 0;
//}


#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <set>
using namespace std;

int solution(int N, int number) {
    int answer = 0;
    vector<set<int>>arr(8);
    for (int i = 0; i < 8; i++) {
        int n = 0;
        for (int j = 0; j <= i; j++) {
            n += N * pow(10, j);
        }
        arr[i].insert(n);
    }


    for (int i = 1; i < 8; i++) {
        for (int j = 0; j < i; j++) {
            for (auto& x: arr[j]) {
                for (auto& y : arr[i - j - 1]) {
                    arr[i].insert(x + y);
                    arr[i].insert(x - y);
                    arr[i].insert(x * y);
                    if (y != 0)arr[i].insert(x / y);
                }
            }
        }
        if (arr[i].find(number) != arr[i].end()) {
            return i + 1;
        }
    }

    return -1;
}
int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    return 0;
}