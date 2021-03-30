#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int>one({ 1,2,3,4,5 });
    vector<int>two({ 2,1,2,3,2,4,2,5 });
    vector<int>three({ 3,3,1,1,2,2,4,4,5,5 });
    int oneScore = 0;
    int twoScore = 0;
    int threeScore = 0;
    int maxScore = 0;
    for (int i = 0; i < answers.size(); i++) {
        
        int ansNum = answers[i];
        if (ansNum == one[i%5]) {
            oneScore++;
            maxScore = max(maxScore, oneScore);
        }
        if (ansNum == two[i%8]) {
            twoScore++;
            maxScore = max(maxScore, twoScore);
        }
        if (ansNum == three[i % 10]) {
            threeScore++;
            maxScore = max(maxScore,threeScore);
        }
    }

    if (maxScore == oneScore)
        answer.push_back(1);
    if (maxScore == twoScore)
        answer.push_back(2);
    if (maxScore == threeScore)
        answer.push_back(3);
    return answer;
}

int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    return 0;
}
