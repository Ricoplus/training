
#include<iostream>
#include<vector>
using namespace std;

//��Ŀ����
//����һ�Ŷ�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
//·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����

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
			//���ﲻ��Ҫ���� ��Ϊ����Ҫpop_back
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