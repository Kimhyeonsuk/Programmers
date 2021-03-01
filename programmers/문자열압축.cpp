#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = s.length();
    for (int i = 1; i <= s.length()/2; i++) {
        string temp = s.substr(0, i);
        int cnt = 1;
        string res = "";
        for (int j = i; j <= s.length(); j += i) {
            string n = s.substr(j, i);
            if (n == temp) {
                cnt++;
            }
            else {
                if (cnt == 1) {
                    res += temp;
                }
                else {
                    res += to_string(cnt) + temp;
                }
                temp = n;
                cnt = 1;
            }
        }
        
        res += s.substr((s.length() / i) * i);
        int a = res.length();
        answer = min(answer, a);
    }
    return answer;
}

int main() {
    solution("aabbaccc");
    return 0;
}