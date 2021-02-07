#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int>s;
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            s.insert(numbers[i] + numbers[j]);
        }
    }

    for (auto it = s.begin(); it != s.end();it++) {
        answer.push_back(*it);
    }
    return answer;
}

int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    vector<int> numbers( { 5, 0, 2, 7 });
    solution(numbers);
    return 0;
}