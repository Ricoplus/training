//��Ŀ����
//�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
#include<iostream>
using namespace std;

struct TreeNode{
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
	bool IsSub(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot2 == NULL)//ע��������pRoot2==NULL���� ����Ϊ�����п������滹�нڵ�
			return true;
		if (pRoot1 == NULL)//���������,���Ȼ����ͻ᷵��trueֵ  
			return false;
		//ע���������ж�ֵ
		if (pRoot1->val == pRoot2->val)
		{
			return IsSub(pRoot1->left, pRoot2->left)
				&& IsSub(pRoot1->right, pRoot2->right);
		}
		else
			return false;
	}
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == NULL || pRoot2 == NULL)
			return false;

		//ע���������ö�·���� ��Ҫ���� ��return
		//�ᵼ�±����� ������ǰ���� �����෴���
		//ֱ�Ӿ�ȥд
		return IsSub(pRoot1, pRoot2)||
			HasSubtree(pRoot1->left, pRoot2)||
			HasSubtree(pRoot1->right, pRoot2);
	}
};