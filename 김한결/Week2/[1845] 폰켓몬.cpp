#include <vector>
#include<unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    int max = nums.size() / 2;

    unordered_set<int> temp;

    for(int i = 0; i < nums.size(); i++)
    {
        temp.insert(nums[i]);
    }

    if(temp.size() > max) 
    {
        return max;
    }
    else
    {
        return temp.size();
    }
}
