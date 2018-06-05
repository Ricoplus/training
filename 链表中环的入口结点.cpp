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
	ListNode * EntryNodeOfLoop(ListNode* pHead)
	{
		if (pHead == NULL||pHead->next==NULL)
			return NULL;
		ListNode* slow = pHead;
		ListNode* fast = pHead;
		while (fast&&fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
				break;
			
		}
		if (fast == slow)
		{
			
			while (pHead != fast)
			{
				pHead = pHead->next;
				fast = fast->next;
			}
			return fast;
		}
		return NULL;
	}
};