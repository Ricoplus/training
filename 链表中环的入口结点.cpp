#include<iostream>
using namespace std;
// 题目描述
// 一个链表中包含环，请找出该链表的环的入口结点。

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x) 
        :val(x)
        ,next(0) 
    {}
};

class Solution {
public:
    ListNode* Meet(ListNode* pHead,ListNode* cur)
    {
        while(pHead!=cur)
        {
            pHead=pHead->next;
            cur=cur->next;
        }
        return cur ;
    }
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead==NULL||pHead->next==NULL)
            return NULL;

        ListNode* slow=pHead->next;//注意这里也需要走一步
        ListNode* fast=pHead->next->next;
        while(fast&&fast->next&&fast!=slow)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast==slow)
        {
            return Meet(pHead,fast);
        }
        else
            return NULL;
    }
};