//题目描述
//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
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
		if (pRoot2 == NULL)//注意这里是pRoot2==NULL结束 ，因为主树有可能下面还有节点
			return true;
		if (pRoot1 == NULL)//如果是子树,则必然上面就会返回true值  
			return false;
		//注意这里是判断值
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

		//注意这里利用短路特性 不要等于 在return
		//会导致本来有 但是提前返回 导致相反结果
		//直接就去写
		return IsSub(pRoot1, pRoot2)||
			HasSubtree(pRoot1->left, pRoot2)||
			HasSubtree(pRoot1->right, pRoot2);
	}
};