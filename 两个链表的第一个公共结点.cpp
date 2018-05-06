#include<iostream>
#include<vector>
using namespace std;

//题目描述
//输入两个链表，找出它们的第一个公共结点。

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) 
		:val(x)
		,next(NULL) 
	{}
};
class Solution {
public:
	ListNode * FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == NULL || pHead2 == NULL)
			return NULL;
		int size1 = 0;
		int size2 = 0;
		ListNode* cur = pHead1;

		while (cur)
		{
			//
			cur = cur->next;
			++size1;
		}
		cur = pHead2;
		while (cur)
		{
			cur = cur->next;
			++size2;
		}
		if (size1 > size2)
		{
			int count = size1 - size2;
			while (count--)
			{
				pHead1 = pHead1->next;
			}
		}
		else
		{
			int count = size2 - size1;
			while (count--)
			{
				pHead2 = pHead2->next;
			}
		}
		while (pHead1&&pHead2)
		{
			if (pHead1 == pHead2)
				return pHead1;
			pHead1 = pHead1->next;
			pHead2 = pHead2->next;

		}
		return NULL;
	}
};