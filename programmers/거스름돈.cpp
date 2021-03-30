
//������ �ڵ� DFS
// n�� 100000�̰� money�� 12345�϶� �ΰ��� dfs�� �������� ��û�� �ð��� �ʰ��ȴ�.
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


////������ �ڵ� n2�� �ð����� �ذᰡ�� 
//1���� �迭�� �̿��Ҽ� ������?
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


//1���� �迭
//������ j>=money�� ���� �˻��� �ʿ䰡 ����.
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