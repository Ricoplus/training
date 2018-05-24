#include<iostream>
using namespace std;
// 题目描述
// 请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的
struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:

    bool Judge(TreeNode* left,TreeNode* right)
    {
        if(left==NULL&&right==NULL)
            return true;
        if(left==NULL||right==NULL)
            return false;
        if(left->val==right->val)
            return Judge(left->right,right->left)&&Judge(left->left,right->right);
        
        return false;
    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return true;
        return Judge(pRoot->left,pRoot->right);
    }

};