//题目描述
//在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

#include<iostream>
using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > v) {
		int i = v.size()-1, j = 0;
		while (i >= 0 && j < v[0].size()-1)
		{
			if (target == v[i][j])
				return true;

			if (target > v[i][j])
				j++;
			else
				i--;

		}
		return false;
	}
};