#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> que;
    
    while (priorities.size() > 0)
    {
        if (priorities[0] >= *max_element(priorities.begin(), priorities.end()))
        {
            que.push(priorities[0]);
        }
        else
        {
            priorities.push_back(priorities[0]);
            if (location == 0)
            {
                location = priorities.size() - 1;
            }
        }

        if (location == 0)
        {
            return que.size();
        }

        priorities.erase(priorities.begin());
        location--;
    }

    return answer;
}
