#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max = 0;
    int min = 0;

    for (size_t i = 0; i < sizes.size(); i++)
    {
        if (sizes[i][0] >= sizes[i][1])
        {
            if (max < sizes[i][0]) max = sizes[i][0];
            if (min < sizes[i][1]) min = sizes[i][1];
        }

        else
        {
            if (max < sizes[i][1]) max = sizes[i][1];
            if (min < sizes[i][0]) min = sizes[i][0];
        }
    }
    
    return min * max;
}
