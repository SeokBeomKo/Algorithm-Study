#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> vv = { {1,2,3,4,5}, {2,1,2,3,2,4,2,5}, {3,3,1,1,2,2,4,4,5,5 } };
    vector<int> vindex = {0,0,0};
    vector<int> vresult = { 0,0,0 };
    
    for (size_t i = 0; i < answers.size(); i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if (answers[i] == vv[j][vindex[j]]) vresult[j]++;
            vindex[j]++;
            if (vindex[j] >= vv[j].size()) vindex[j] = 0;
        }
    }

    int max = *max_element(vresult.begin(), vresult.end());
    if (max == 0)
    {
        return answer;
    }
    for (size_t i = 0; i < vresult.size(); i++)
    {
        if (vresult[i] == max)
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}

int main()
{
    vector<int> answers = { 1,2,3,4,5 };

    solution(answers);
}
