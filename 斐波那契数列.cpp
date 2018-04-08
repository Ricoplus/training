//题目描述
//大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。(n <= 39)
//F(0)=0，F(1)=1, F(n)=F(n-1)+F(n-2)（n>=2，n∈N*）
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;

		vector<int>	a;
		a.resize(n+1);
		a[0] = 1;
		a[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			a[i] = a[i - 1] + a[i - 2];
		}
		
		return a[n];
	}
};