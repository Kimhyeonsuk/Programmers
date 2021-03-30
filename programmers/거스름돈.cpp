
//실패한 코드 DFS
// n이 100000이고 money가 12345일때 두개만 dfs로 내려가도 엄청난 시간이 초과된다.
//#include <string>
//#include <vector>
//
//using namespace std;
//int res = 0;
//void dfs(int cnt, int left, vector<int>& money) {
//    if (left < 0)
//        return;
//    if (left == 0) {
//        res++;
//        return;
//    }
//    if (cnt >= money.size() && left > 0) {
//        return;
//    }
//
//    int val = left / money[cnt];
//    for (int i = 0; i <= val; i++) {
//        dfs(cnt + 1, left - i * money[cnt], money);
//    }
//}
//int solution(int n, vector<int> money) {
//    int answer = 0;
//    dfs(0, n, money);
//    answer = res;
//    return answer;
//}


////성공한 코드 n2의 시간으로 해결가능 
//1차원 배열을 이용할수 있을까?
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(int n, vector<int> money) {
//    int answer = 0;
//    vector<vector<int>>dp(money.size(), vector<int>(n + 1, 0));
//    for (int j = 0; j <= n; j++) {
//        if (j % money[0] == 0) {
//            dp[0][j] = 1;
//        }
//    }
//    for (int i = 1; i < money.size(); i++) {
//        for (int j = 0; j <= n; j++) {
//            if (j >= money[i]) {
//                dp[i][j] = dp[i - 1][j] + dp[i][j - money[i]];
//            }
//            else {
//                dp[i][j] = dp[i - 1][j];
//            }
//
//        }
//    }
//    answer = dp[money.size() - 1][n];
//    return answer;
//}


//1차원 배열
//어차피 j>=money일 때는 검사할 필요가 없다.
#include <vector>
#include <string>
using namespace std;
int solution(int n,vector<int>money) {
    int answer = 0;
    vector<int>dp(n + 1);

    for (int i = 0; i <= n; i++) {
        if (i % money[0] == 0) {
            dp[i] = 1;
        }
    }

    for (int i = 1; i < money.size(); i++) {
        for (int j = money[i]; j <= n; j++) {
            dp[j] += dp[j - money[i]];
        }
    }
    answer = dp[n];
    return answer;
}