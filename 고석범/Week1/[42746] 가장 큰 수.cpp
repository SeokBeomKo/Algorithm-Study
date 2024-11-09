#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(int a, int b)
{
    string astring = to_string(a) + to_string(b);
    string bstring = to_string(b) + to_string(a);
    
    return astring > bstring;
}

string solution(vector<int> numbers) 
{
    if (numbers.size() > 100000 || numbers.empty())
        return "0";
    for (size_t i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] < 0 || numbers[i] > 1000)
            return "0";
    }

    string answer = "";

    sort(numbers.begin(), numbers.end(), compare);

    if (numbers[0] == 0) return "0";
    
    for (size_t i = 0; i < numbers.size(); i++)
    {
        answer.append(to_string(numbers[i]));
    }

    return answer;
}
