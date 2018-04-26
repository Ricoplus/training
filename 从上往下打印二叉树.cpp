#include<iostream>
#include<vector>
#include<queue>
using namespace std;



//题目描述
//从上往下打印出二叉树的每个节点，同层节点从左至右打印。

struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) 
		:val(x)
		,left(NULL
		,right(NULL) 
	{}
};
class Solution{
public:
	vector<int> PrintFromTopToBottom(TreeNode* root){
		vector<int> v;
		if (root == NULL)
			return v;
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty())
		{
			TreeNode* tmp = q.front();
			q.pop();
			v.push_back(tmp->val);
			if (tmp->left)
				q.push(tmp->left);
			if(tmp->right)
				q.push(tmp->right);
		}
		return v;
	}
};