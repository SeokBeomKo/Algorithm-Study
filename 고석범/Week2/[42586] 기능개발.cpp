#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int pivot = 0;
    for (size_t i = 0; i < progresses.size(); i++)
    {
        progresses[i] = (ceil((100 - progresses[i]) / (double)speeds[i]));

        if (answer.empty() || pivot < progresses[i])
        {
            answer.push_back(1);
        }
        else
        {
            ++answer.back();
        }

        if (progresses[i] > pivot)
        {
            pivot = progresses[i];
        }
    }

    return answer;
}
