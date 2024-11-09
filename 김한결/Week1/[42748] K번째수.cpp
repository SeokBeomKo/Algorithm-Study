#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;
    vector<int> temp;

    for(int i = 0; i < commands.size(); i++)
    {
        for(int j = commands[i][0] - 1; j < commands[i][1]; j++)
        {
            temp.push_back(array[j]);
        }

        for(int i = temp.size() - 1; i >= 1; i--)
        {
            for(int j = 0; j < i; j++)
            {
                if(temp[j] > temp[j + 1])
                {
                    int n = temp[j];
                    temp[j] = temp[j+1];
                    temp[j+1] = n;
                }
            }
        }

        answer.push_back(temp[commands[i][2]-1]);
        temp.clear();
    }
    return answer;
}
