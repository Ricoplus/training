#include<string>
#include<iostream>
#include<stdlib.h>
using namespace std;
// 题目描述
// 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
class Solution {
public:
	int StrToInt(string str) {
		char* p = (char*)str.c_str();
		int flag = 1;
		int sum = 0;
		while (isspace(*p))
		{
			p++;
		}
		if (*p == '-')
		{
			flag = -1;
			p++;
		}
		else if (*p == '+')
		{
			p++;
		}
		while (*p)
		{
			if ('0' <= *p &&*p<= '9')
				sum = sum * 10 + (*p - '0');
			else
            //记住要是有非数字 返回0
				return 0;
			p++;
		}
		return sum * flag;
	}
};