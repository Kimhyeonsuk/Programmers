#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(int n) {
    string arr[3] = { "4","1","2" };
    string answer = "";
    while (n != 0) {
        answer = arr[n % 3] + answer;
        n = n / 3;
    }
    return answer;
}

int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    return 0;
}