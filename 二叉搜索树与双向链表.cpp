#include<iostream>
using namespace std;
#include<stack>


//��Ŀ����
//����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
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