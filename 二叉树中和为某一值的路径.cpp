
#include<iostream>
#include<vector>
using namespace std;

//题目描述
//输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
//路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) 
		:val(x)
		,left(NULL)
		,right(NULL) 
	{}
};
class Solution {
public:
	void Find(TreeNode* root, int expectNumber, vector<vector<int>>& v, vector<int>& a)
	{
		a.push_back(root->val);
		if (root->left == NULL && root->right == NULL)
		{
			if (expectNumber - root->val == 0)
				v.push_back(a);
			//这里不需要返回 因为还需要pop_back
		}
		if (root->left)
			Find(root->left, expectNumber - root->val, v, a);
		if (root->right)
			Find(root->right, expectNumber - root->val, v, a);
		a.pop_back();
	}
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int> > v;
		vector<int> a;
		if (root == NULL)
			return v;

		Find(root, expectNumber, v, a);
		return v;
	}
};