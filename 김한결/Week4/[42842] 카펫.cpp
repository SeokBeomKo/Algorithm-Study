#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) 
{
    vector<int> answer;

    int total = brown + yellow;

    for(int height = 1; height < total; height++)
    {
        if(total % height == 0)
        {
            int width = total / height;
            int y = (height - 2) * (width - 2);
            int b = total - y;

            if(y == yellow && b == brown)
            {
                answer.push_back(width);
                answer.push_back(height);

                return answer;
            }
        }
    }
}
