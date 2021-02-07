#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<pair<int,int>>q;
    int leftTruckNum = truck_weights.size();
    int truckIdx = 0;
    int total = 0;
    int sec = 0;
    total += truck_weights[0];
    q.push({ sec,truckIdx++ });
    
    while (leftTruckNum != 0) {
        sec++;
        pair<int, int>truck = q.front();
        if (sec - truck.first == bridge_length)
        {
            q.pop();
            leftTruckNum--;
            total -= truck_weights[truck.second];
        }
        if (truckIdx == truck_weights.size())continue;//�ٸ��� �����ϱ⸦ ����ϴ� Ʈ���� ������ continue
        if (total + truck_weights[truckIdx] <= weight) {//���� Ʈ���� �ٸ��� ������ �� ������
            total += truck_weights[truckIdx];
            q.push({ sec,truckIdx++ });
        }
    }
    
    return sec+1;
}

int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    vector <int>list({ 7,4,5,6 });
    solution(2, 10, list);
    return 0;
}