#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) 
{
    while (k > 0) 
    {
        int i = 0;
        
        while (i < number.size() - 1 && number[i] >= number[i + 1]) 
        {
            i++;
        }

        number.erase(i, 1);
        k--;
    }

    return number;
}
