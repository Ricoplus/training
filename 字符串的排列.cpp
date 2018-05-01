#include<iostream>
#include<vector>
using namespace std;


//题目描述
//输入一个字符串, 按字典序打印出该字符串中字符的所有排列。例如输入字符串abc, 则打印出由字符a, b, c所能排列出来的所有字符串abc, acb, bac, bca, cab和cba。
class Solution {
	vector<string> v;
public:
	void Per(string& str, int begin)
	{
		if (str[begin] == '\0')
		{
			v.push_back(str);
			return;
		}
		for (int i = begin; i < str.size(); i++)
		{
			if (begin != i && str[begin] == str[i])
				continue;
			swap(str[begin], str[i]);
			Per(str, begin + 1);
			swap(str[begin], str[i]);
		}
	}
	vector<string> Permutation(string str){
		if (str.size() == 0)
			return v;
		Per(str, 0);
		sort(v.begin(), v.end());
		return v;
	}
};