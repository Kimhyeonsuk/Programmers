//#include <string>
//#include <vector>
//#include <queue>
//using namespace std;
//
//vector<int> solution(vector<string> operations) {
//    vector<int> answer;
//    priority_queue<int,vector<int>, greater<int>>pq;
//    priority_queue<int, vector<int>, less<int>>tpq;
//    int cnt = 0;
//    for (int i = 0; i < operations.size(); i++) {
//        string op = operations[i].substr(0, 1);
//        int num =stoi(operations[i].substr(2));
//        
//        if (cnt == 0) {
//            while (!pq.empty())pq.pop();
//            while (!tpq.empty())tpq.pop();
//        }
//
//        if (op == "I") {
//            pq.push(num);
//            tpq.push(num);
//            cnt++;
//        }
//        else if (op == "D"&&num<0&&cnt!=0) {
//            pq.pop();
//            --cnt;
//        }
//        else if (op == "D" && num >= 0&&cnt!=0) {
//            tpq.pop();
//            --cnt;
//        }
//    }
//
//    if (cnt != 0) {
//        answer.push_back(tpq.top());
//        answer.push_back(pq.top());
//    }
//    else {
//        answer.push_back(0);
//        answer.push_back(0);
//    }
//
//    return answer;
//}
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    set<int>pq;
    for (int i = 0; i < operations.size(); i++) {
        string op = operations[i].substr(0, 1);
        int num = stoi(operations[i].substr(2));
       
        if (op == "I") {
            pq.insert(num);
        }
        else if (op == "D") {
            if (num == 1)
            {
                set<int>::iterator iter;
                iter = pq.end();
                if (iter != pq.begin()) {
                    iter--;
                    pq.erase(iter);
                }
            }
            else {
                set<int>::iterator iter;
                iter = pq.begin();
                if (iter != pq.end()) {
                    pq.erase(iter);
                }
            }
        }
    }
    if (!pq.empty()) {
        answer.push_back(*pq.begin());
        answer.push_back(*pq.rbegin());
    }
    else {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
} 