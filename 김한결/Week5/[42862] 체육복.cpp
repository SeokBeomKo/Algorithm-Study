#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) 
{
    int answer = 0;
    vector<int> student;

    for(int i = 0; i < n; i++)
    {
        student.push_back(1);
    }

    for(int i = 0; i < lost.size(); i++)
    {
        student[lost[i]-1]--;
    }

    for(int i = 0; i < reserve.size(); i++)
    {
        student[reserve[i]-1]++;
    }

    for(int i = 0; i < student.size(); i++)
    {
        if(student[i] == 2)
        {
            if( i-1 >= 0 && student[i-1] == 0)
            {
                student[i] = 1;
                student[i-1] = 1;
            }
            else if(student[i+1] == 0 && i+1 < student.size())
            {
                student[i] = 1;
                student[i+1] = 1;
            }
        }
    }

    for(int i = 0; i < student.size(); i++)
    {
        if(student[i] > 0 ) answer++;
    }

    return answer;
}
