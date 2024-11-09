#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size());
	stack<int> stack; 
	int top;

	for (size_t i = 0; i < prices.size(); i++)
	{
		while (!stack.empty() && prices[stack.top()] > prices[i])
		{
			top = stack.top();
			stack.pop();
			answer[top] = i - top;
		}
		stack.push(i);
	}

	while (!stack.empty())
	{
		top = stack.top();
		stack.pop();
		answer[top] = prices.size() - top - 1;
	}

    return answer;
}
