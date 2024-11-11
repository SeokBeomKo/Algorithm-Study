#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) 
{
    int answer = 1;
	unordered_map<string, int> um;


	for (size_t i = 0; i < clothes.size(); i++)
	{
		um[clothes[i][1]]++;
	}

	for (auto e : um)
	{
		answer *= e.second + 1;
	}
    return answer - 1;
}
