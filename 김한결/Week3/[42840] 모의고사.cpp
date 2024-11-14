#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) 
{
    vector<int> person1 = {1, 2, 3, 4, 5};
    vector<int> person2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> person3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    int correct1 = 0;
    int correct2 = 0;
    int correct3 = 0;

    for(int i = 0; i < answers.size(); i++)
    {
        int index1 = i % person1.size();
        int index2 = i % person2.size();
        int index3 = i % person3.size();

        if(answers[i] == person1[index1]) correct1 ++;
        if(answers[i] == person2[index2]) correct2 ++;
        if(answers[i] == person3[index3]) correct3++;
    }

    int temp = max(max(correct1, correct2), correct3);

    vector<int> answer;   
    if(correct1 == temp) answer.push_back(1);
    if(correct2 == temp) answer.push_back(2);
    if(correct3 == temp) answer.push_back(3); 

    return answer;
}
