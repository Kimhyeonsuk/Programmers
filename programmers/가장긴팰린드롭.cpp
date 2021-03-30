#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int solution(string s)
{
    int answer = 0;

    for (int i = 0; i < s.size(); i++) {
        int start = i-1;
        int end = i+1;

        int cCnt = 0;//기준점이 없이 두개씩 비교할 경우
        int sCnt = 1;//기준점을 놓고(i) 양옆에 두개씩 비교할 경우
        bool cChk = true;
        bool sChk = true;
        while (1) {
            if (s[start] == s[end - 1]&&start>=0&&(end-1)<s.size()) {
                cCnt += 2;
            }
            else {
                cChk = false;
            }
            if (s[start] == s[end]&&start>=0&&end<s.size()) {
                sCnt += 2;
            }
            else {
                sChk = false;
            }
            start--;
            end++;
            if (cChk == false && sChk == false)
                break;
        }
        answer = max(answer, cCnt);
        answer = max(answer, sCnt);
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    //cout << "Hello Cpp" << endl;

    return answer;
}