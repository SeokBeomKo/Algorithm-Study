#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) 
{
    vector<int> answer;

    for (int i = 0; i < prices.size(); i++)
    {
        int temp = 0;

        for (int j = i + 1; j < prices.size(); j++)
        {
            if (prices[i] <= prices[j])
            {
                temp++ ;
            }
            else
            {
                temp++; 
                break;
            }
        }

        answer.push_back(temp);
    }

    return answer;
}
