#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    map<string, int> m;

    for (size_t i = 0; i < participant.size(); i++)
    {
        m[participant[i]] += 1;
    }
    for (size_t i = 0; i < completion.size(); i++)
    {
        m[completion[i]] -= 1;
    }

    for (auto iter = m.begin(); iter != m.end(); iter++) 
    {
        if (iter->second != 0)
        {
            return iter->first;
        }
    }
    return answer;
}
