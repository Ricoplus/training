#include<iostream>
#include<stack>
using namespace std;

//题目描述
//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

//一个作为主栈
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		int top = 0;
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}

		top = stack2.top();
		stack2.pop();
		while (!stack2.empty())
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
		return top;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};