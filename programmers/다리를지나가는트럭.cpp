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
    
    sec++;//2����
    if (total + truck_weights[1] <= weight) { //����Ʈ���� ���ü��ִ� ���
        q.push(truck_weights[1]);
        total = total + truck_weights[1];
    }

    int truckIdx = 2;

    //������� �ٸ����� Ʈ���� �ϳ��� �ְų� �� Ʈ���� �ְų�

    while (trucknum != 0) {
        sec++;
        total -= q.front();
        q.pop();
        trucknum--;

        int nextTruckWeight = truck_weights[truckIdx];
        if (total + nextTruckWeight > weight)//Ʈ���� ���԰� �ٸ��� ���Ը� �������
        {
            continue;
        }
        else {//Ʈ���� �ö� �� �ִ°��
            total = total + truck_weights[truckIdx];
            q.push(truck_weights[truckIdx++]);
        }
    }
    return answer;
}