#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    stack<char> stack;

    for (size_t i = 0; i < s.length(); i++)
    {
        if (stack.empty() || s[i] == '(') 
        {
            stack.push(s[i]);
        }
        if (stack.top() == '(' && s[i] == ')')
        {
            stack.pop();
        }
    }

    return stack.empty();
}
