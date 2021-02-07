#include <iostream>

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int >q;
    int trucknum = truck_weights.size();
    int total = 0;
    int sec = 0;
    sec++;
    total = truck_weights[0];
    q.push(truck_weights[0]);
    
    sec++;//2초후
    if (total + truck_weights[1] <= weight) { //다음트럭이 들어올수있는 경우
        q.push(truck_weights[1]);
        total = total + truck_weights[1];
    }

    int truckIdx = 2;

    //현재까지 다리위에 트럭이 하나만 있거나 두 트럭이 있거나

    while (trucknum != 0) {
        sec++;
        total -= q.front();
        q.pop();
        trucknum--;

        int nextTruckWeight = truck_weights[truckIdx];
        if (total + nextTruckWeight > weight)//트럭의 무게가 다리의 무게를 넘을경우
        {
            continue;
        }
        else {//트럭이 올라갈 수 있는경우
            total = total + truck_weights[truckIdx];
            q.push(truck_weights[truckIdx++]);
        }
    }
    return answer;
}