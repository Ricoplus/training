#include<iostream>
#include<stack>
using namespace std;

// 题目描述
// 给定一颗二叉搜索树，请找出其中的第k大的结点。
//例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。

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
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==NULL)
            return NULL;
        int count = 0;
        stack<TreeNode*> s;
        TreeNode* cur=pRoot;
        while(cur||!s.empty())
        {
            while(cur)
            {
                s.push(cur);
                cur=cur->left;
            }
            TreeNode* top = s.top();
            s.pop();           
            count++;
            if(count==k)
                return top;
             cur=top->right;
        }
        return NULL;
    }
};