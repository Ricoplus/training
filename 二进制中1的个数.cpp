#include<iostream>
using namespace std;

//题目描述
//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
class Solution {
public:
	int  NumberOf1(int n) {
		int sum = 0;

		if (n < 0)
		{
			n = n & 0X7FFFFFFF;
			sum++;
		}
		/*
		int i = 31;
		while (i>=0)
		{
		sum += (n& (1<<i))>>i;
		i--;
		}*/
		//较优解法
		while (n != 0)
		{
			sum += n & 1;
			n = n >> 1;
		}
		return sum;
	}
};