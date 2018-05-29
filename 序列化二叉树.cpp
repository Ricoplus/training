#include<iostream>
#include<string>
#include<stdlib.h>
#include<string.h>
using namespace std;
// 题目描述
// 请实现两个函数，分别用来序列化和反序列化二叉树

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
    void Serialize(TreeNode *root,string& s)
    {
        if(root==NULL)
        {
            s +='#';
            return;
        }
        else
        {
            s+=to_string(root->val);
            s+=',';
            Serialize(root->left,s);
            Serialize(root->right,s);
        }
    }
    char* Serialize(TreeNode *root) {    
        //序列化
        if(root==NULL)
            return NULL;
        string s;
        Serialize(root,s);
        char* p = new char[s.size()+1];
        
        for(size_t i = 0; i < s.size(); i++)
        {
            p[i]=s[i];
        }
        p[s.size()]='\0';
        
        return p;
    }
    //特比注意这一一定要加引用
    TreeNode* _Deserialize(char *& str) {
        if(*str=='#')
        {
            return NULL;
        }
        else
        {
            int num = 0;
            while(*str!='\0'&&*str!=',')
            {
                num=num*10+(*str-'0');
                ++str;
            }
            TreeNode* root = new TreeNode(num);
            root->left=_Deserialize(++str);
            root->right=_Deserialize(++str);
            return root;
        }
    }
     TreeNode* Deserialize(char *str) {
        if(str==NULL)
            return NULL;
        return _Deserialize(str);
     }
};