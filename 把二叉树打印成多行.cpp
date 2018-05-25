
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// 题目描述
// 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。

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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> v;
            if(pRoot==NULL)
                return v;
            queue<TreeNode*> q;
            q.push(pRoot);
            while(!q.empty())
            {
                int size= q.size();
                vector<int> tmp;
                while(size--)
                {
                    TreeNode* top = q.front();
                    tmp.push_back(top->val);
                    q.pop();
                    if(top->left)
                    {
                        q.push(top->left);
                    }
                    if(top->right)
                    {
                        q.push(top->right);
                    }
                }
                v.push_back(tmp);
            }
            
            return v;
        }
};