#include<iostream>
#include<vector>
#include<queue>
using namespace std;



//��Ŀ����
//�������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��

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