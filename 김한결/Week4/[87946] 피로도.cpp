#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) 
{
    vector<int> temp;
    vector<vector<int>> permutations; 

    for (int i = 0; i < dungeons.size(); i++) 
    {
        temp.push_back(i);
    }

    do 
    {
        permutations.push_back(temp);  
    } 
    while (next_permutation(temp.begin(), temp.end()));

    int answer = 0;

    for (int i = 0; i < permutations.size(); i++) 
    {
        int count = 0;
        int currentK = k; 

        for (int j = 0; j < dungeons.size(); j++) 
        {
            if (dungeons[permutations[i][j]][0] <= currentK) 
            { 
                currentK -= dungeons[permutations[i][j]][1];
                count++;
            }
        }

        answer = max(answer, count);  
        if (answer == dungeons.size()) return dungeons.size();  
    }
    return answer;
}
