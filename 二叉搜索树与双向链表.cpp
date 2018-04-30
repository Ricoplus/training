#include<iostream>
using namespace std;
#include<stack>


//题目描述
//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
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


class Solution{
public:
	TreeNode * Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL)
			return NULL;
		TreeNode* cur = pRootOfTree;
		TreeNode* prev = NULL;
		TreeNode* head = NULL;
		stack<TreeNode*> s;
		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->left;
			}
			TreeNode* top = s.top();
			s.pop();
			if (head == NULL)
				head = top;
			else
			{
				prev->right = top;
				top->left = prev;
			}
			prev = top;
			cur = top->right;
		}
		return head;
	}
};