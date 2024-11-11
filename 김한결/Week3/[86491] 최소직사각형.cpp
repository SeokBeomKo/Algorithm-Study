#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) 
{
    int maxWidth = 0;
    int maxLength = 0;

    for (int i = 0; i < sizes.size(); i++)
    {
        if (sizes[i][0] < sizes[i][1]) swap(sizes[i][0], sizes[i][1]);
    }

    for (int i = 0; i < sizes.size(); i++)
    {
        maxWidth = max(maxWidth, sizes[i][0]);
        maxLength = max(maxLength, sizes[i][1]);
    }

    return maxWidth * maxLength;
}
