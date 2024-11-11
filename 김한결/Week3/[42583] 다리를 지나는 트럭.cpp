#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    int time = 0;
    int index = 0;
    int count = 0;
    int totalWeight = 0;

    queue<int> bridgeTruck;

    while(count < truck_weights.size())
    {   
        time ++;
       
        if(bridgeTruck.size() == bridge_length)
        {
            if(bridgeTruck.front() != 0) count++;

            totalWeight -= bridgeTruck.front();
            bridgeTruck.pop();
        }

        if(totalWeight + truck_weights[index] <= weight && index < truck_weights.size())
        {
            bridgeTruck.push(truck_weights[index]);
            totalWeight += truck_weights[index];
            index++;
        }
        else
        {
            bridgeTruck.push(0);
        }
    }

    return time;
}
