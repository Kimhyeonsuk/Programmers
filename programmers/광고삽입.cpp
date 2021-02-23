#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//100½Ã°£
//100* 60* 60
int allTime[360000];
int convertToInt(string s) {
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    int c = stoi(s.substr(6, 2));

    return h * 60 * 60 + m * 60 + c;
}
string convertToStr(int sec) {

    string h = "";
    string m = "";
    string c = "";

    int hour = sec / 3600;
    if (hour <= 9) {
        h = "0";
    }
    h += to_string(hour);
    sec = sec % 3600;

    int minute = sec / 60;
    if (minute <= 9) {
        m = "0";
    }
    m += to_string(minute);
    sec = sec % 60;

    if (sec <= 9) {
        c = "0";
    }
    c += to_string(sec);

    return h + ":" + m + ":" + c;
}
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    for (int i = 0; i < logs.size(); i++) {
        string t = logs[i];
        int start = convertToInt(t.substr(0, 8));
        int end = convertToInt(t.substr(9, 8));
        for (int j = start; j < end; j++) {
            allTime[j] ++;
        }
    }

    int pTime = convertToInt(play_time);
    int advTime = convertToInt(adv_time);

    long long res=0;
    long long uses = 0;
    int startTime = 0;
    for (int i = 0; i < advTime; i++) {
        res += allTime[i];
    }
    uses = res;
    for (int i = 1; i <= pTime - advTime; i++) {
        //res = max(res, res - allTime[i - 1] + allTime[advTime + i-1]);
        string a = convertToStr(i);
        uses = uses - allTime[i - 1] + allTime[advTime + i - 1];
        if (res < uses) {
            res = uses;
            startTime = i;
        }
    }
    return convertToStr(startTime);
}

int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    vector<string > vec({ "69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00" });
    solution("99:59:59", "25:00:00", vec);
    return 0;
}

