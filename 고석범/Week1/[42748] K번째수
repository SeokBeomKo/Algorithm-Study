#include <string>
#include <vector>

using namespace std;

vector<int> sort(vector<int> array)
{
    vector<int> answer = array;
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (answer[i] < answer[j])
            {
                answer.insert(answer.begin() + j, array[i]);
                answer.erase(answer.begin() + i + 1);
            }
        }
    }
    return answer;
}

int result(vector<int> array, vector<int> commands)
{
    vector<int> answer;

    // cut
    for (size_t i = 0; i < array.size(); i++)
    {
        if (commands[0] <= i + 1 && commands[1] > i)
        {
            answer.push_back(array[i]);
        }
    }

    // sort
    answer = sort(answer);

    return answer[commands[2] - 1];
}

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++)
    {
        answer.push_back(result(array, commands[i]));
    }

    return answer;
}
