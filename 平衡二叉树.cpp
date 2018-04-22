#include<iostream>
using namespace std;

//题目描述
//输入一棵二叉树，判断该二叉树是否是平衡二叉树。
//O(N*N)
class Solution{
public:
	int depth(TreeNode* pRoot)
	{
		if(pRoot == NULL)
			return 0;
		
		int l = depth(pRoot->left);
		int r = depth(pRoot->right);
		int d = (l > r ? l : r)+1;
		
		return d;
	}
	bool IsBalanced_Solution(TreeNode* pRoot){
		if (pRoot == NULL)
			return true;
		int l = depth(pRoot->left);
		int r = depth(pRoot->right);
		return abs(l-r)<2&&IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
	}
};
//O(N)
class Solution{
public:
	bool IsBalanced(TreeNode* pRoot, int& d)
	{
		if (pRoot == NULL)
		{
			d = 0;
			return true;
		}
		int left = 0, right = 0;
		if (IsBalanced(pRoot->left,left) && IsBalanced(pRoot->right,right))
		{
			int dif = abs(left - right);
			if (dif > 1)
				return false;
			d = (left > right ? left : right) + 1;
			return true;
		}
		return false;
	}
	bool IsBalanced_Solution(TreeNode* pRoot){
		if (pRoot == NULL)
			return true;
		int d = 0;
		return IsBalanced(pRoot, d);
	}
};