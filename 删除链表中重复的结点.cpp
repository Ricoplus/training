// 题目描述
// 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) 
        :val(x)
        ,next(0) 
    {}
};

class Solution {
public:
    ListNode * deleteDuplication(ListNode* pHead)
	{   
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		else
		{
			ListNode* newhead = new ListNode(-1);
			//这里一定要注意设置头结点,防止第一个就是重复的,但是还要注意的是刚开始要让newhead->next=pHead
			newhead->next = pHead;
			ListNode* prev = newhead;
			ListNode* cur = pHead;
            //多了个cur->next是因为函数内部要用cur->next
			while (cur&&cur->next)
			{
				ListNode* next = cur->next;
				if (next->val == cur->val)
				{
					while (next&&next->val == cur->val)
						next = next->next;
					//相当于删除节点
					prev->next = next;
					cur = next;
					//防止cur也是重复的
				}
				else
				{
					prev = cur;
					cur = cur->next;
				}
			}
			return newhead->next;
		}
	}
};