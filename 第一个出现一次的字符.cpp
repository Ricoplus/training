#include<iostream>
#include<vector>
using namespace std;

//题目描述
//在一个字符串(1 <= 字符串长度 <= 10000，全部由字母组成)中找到第一个只出现一次的字符, 并返回它的位置
class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		if (str.size() == 0)
			return -1;
		vector<int> v(256, 0);
		int i = 0;
		int size = (int)str.size();
		for (i = 0; i < size; i++)
			v[str[i]]++;
		for (i = 0; i < size; i++)
		{
			if (v[str[i]] == 1)
				return i;
		}
		return 0;
	}
};