#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<int> start;
    vector<int>end;

    for (int i = 0; i < lines.size(); i++) {
        int h = stoi(lines[i].substr(11, 2))*60*60*1000;
        int m = stoi(lines[i].substr(14, 2))*60*1000;
        int s = stoi(lines[i].substr(17, 2))*1000;
        int ms = stoi(lines[i].substr(20, 3));
        int time = stod(lines[i].substr(24, 5))*1000;

        start.push_back(h + m + s + ms - time + 1);
        end.push_back(h + m + s + ms);
    }


    return answer;
}

int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    return 0;
}
