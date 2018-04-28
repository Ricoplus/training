#include<iostream>
#include<vector>
using namespace std;

//题目描述
//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes, 否则输出No。假设输入的数组的任意两个数字都互不相同。

class Solution{
public:
	bool Judge(int left, int right, vector<int>& a)
	{
		if (left >= right)
			return true;

		int i = right-1;

		while (i > left&&a[i] > a[right])
			i--;
		
		for (int j = i-1; j >=left; j--)
		{
			if (a[j] > a[right])
				return false;
		}
		return Judge(left, i - 1, a) && (Judge(i, right - 1, a));


		/*int i = left;
		while (i < right&&a[i] < a[right])
			++i;
		for (int j=i+1;j<right;j++)
		{
			if (a[j] < a[right])
				return false;
		}
		return Judge(left, i, a) && Judge(i+1, right - 1, a);*/
		
	}
	bool VerifySquenceOfBST(vector<int> sequence)
	{
		if (sequence.size() == 0)
			return false;
		return Judge(0, sequence.size() - 1, sequence);
	}
};