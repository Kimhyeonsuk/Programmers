#include <iostream>
using namespace std;

long long solution(int w, int h) {
    long long answer = 1;
    long long longw = (long)w;
    long long longh = (long)h;
    long long gcdVal = gcd(longw, longh);

    answer = longw * longh - (longw + longh - gcdVal);
    return answer;
}

long long gcd(long long w, long long h) {
    long long big = w > h ? w : h;
    long long small = w > h ? h : w;

    while (small != 0) {
        long long n = big % small;
        big = small;
        small = n;
    }

    return big;
}

int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    return 0;;
}