#include<iostream>
using namespace std;
// 题目描述
// 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

struct TreeLinkNode{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
//明确一点  这个结点本身和左边已经访问过了
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode==NULL)
         return NULL;
        if(pNode->right)
        {
            TreeLinkNode* cur=pNode->right;
            while(cur->left)
                cur=cur->left;
            return cur;
        }
        while(pNode->next)
        {
            TreeLinkNode* cur = pNode->next;
            if(cur->left==pNode)
                return cur;
            pNode = pNode -> next;
        }
        return NULL;
    }
};