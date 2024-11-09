#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) 
{
    if (citations.size() < 1 && citations.size() > 1000)
    {
        return 0;
    }
    int answer = 0;
    sort(citations.begin(), citations.end());

    for (int i = citations.size() - 1; i >= 0; i--)
    {
        if (citations[i] < 0 && citations[i] > 10000)
        {
            return 0;
        }
        if (i == 0)
        {
            if (citations.size() - i <= citations[i])
                return citations.size() - i;
        }
        answer = min((int)citations.size() - i, citations[i]);
        if (citations[i - 1] < answer)
        {
            return answer;
        }
    }
    return 0;
}
