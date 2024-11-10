#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    int answer = 0;
    queue<int> que;
    int truck = 0;
    int bridge_weight = 0;

    for (int i = 0; i < bridge_length; i++) 
    {
        que.push(0);
    }

    while (truck < truck_weights.size() || bridge_weight > 0)
    {
        answer++;

        bridge_weight -= que.front();
        que.pop();


        if (truck < truck_weights.size() && bridge_weight + truck_weights[truck] <= weight)
        {
            que.push(truck_weights[truck]);
            bridge_weight += truck_weights[truck];
            truck++;
        }
        else
        {
            que.push(0);
        }
        
    }

    return answer;
}
