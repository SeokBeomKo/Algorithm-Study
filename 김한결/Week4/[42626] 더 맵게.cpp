#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) 
{
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq; // 오름차순 queue

    for(int i = 0; i < scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }
    
    while(pq.top() < K && pq.size() > 1)
    {
        int first = pq.top();
        pq.pop();

        int second = pq.top();
        pq.pop();

        int newScoville = first + second * 2;

        pq.push(newScoville);

        answer++;
    }

    if(pq.top() < K) return -1;

    return answer;
}
