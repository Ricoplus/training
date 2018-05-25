#include<iostream>
#include<vector>
#include<dequeue>
using namespace std;
//题目描述
//请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
//第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
	vector<vector<int>> Print(TreeNode* pRoot) {
		vector<vector<int>> v;
		if (pRoot == NULL)
			return v;
		deque<TreeNode*> q;
		deque<TreeNode*> p;

		int index = 0;
		q.push_back(pRoot);

		while (!q.empty() || !p.empty())
		{
			vector<int> tmp;
			//当前是奇数行(读的时候从左边向右边) 存的是偶数行(从右向左)
			while (!q.empty())
			{
				TreeNode* top = q.front();
				q.pop_front();
				tmp.push_back(top->val);
				if (top->left)
				{
					p.push_front(top->left);
				}
				if (top->right)
				{
					p.push_front(top->right);
				}
			}
			if (tmp.size() != 0)
				v.push_back(tmp);
			vector<int> tmp2;
			//当前是偶数行(读的时候从右向左) 存的是偶数行(从左边向右边)
			while (!p.empty())
			{
				TreeNode* top = p.front();
				p.pop_front();
				tmp2.push_back(top->val);
				if (top->right)
				{
					q.push_front(top->right);
				}
				if (top->left)
				{
					q.push_front(top->left);
				}
			}
			if(tmp2.size()!=0)
				v.push_back(tmp2);
		}
		return v;
	}
};