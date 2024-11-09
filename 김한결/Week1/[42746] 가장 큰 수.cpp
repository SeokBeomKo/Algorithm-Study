#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) 
{
    vector<string> temp;
    string answer = "";

    for(int i = 0; i < numbers.size(); i++)
    {
        temp.push_back(to_string(numbers[i]));
    }

    sort(temp.begin(), temp.end(), comp);
    
    if(temp[0] == "0") return "0";

    for(int i = 0; i < temp.size(); i++)
    {
        answer.append(temp[i]);
    }

    return answer;
}

