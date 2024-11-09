#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) 
{
    queue<int> delay;

    while(true)
    {
        int max = *max_element(priorities.begin(), priorities.end());
        
        if(max > priorities[0])
        {
            priorities.push_back(priorities[0]);
            priorities.erase(priorities.begin());
            location--;

            if( location < 0 ) location = priorities.size() - 1;
        }
        else if(max == priorities[0])
        {
            delay.push(priorities[0]);                
            priorities.erase(priorities.begin());
            location--;

            if(location < 0)
            {
                return delay.size();
                break;
            }
        }
    }
}
