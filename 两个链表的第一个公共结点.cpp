#include<iostream>
#include<vector>
#include<set>
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
	//1.map
	ListNode * FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
	{
		set<ListNode*> s;
		while (pHead1)
		{
			s.insert(pHead1);
			pHead1 = pHead1->next;
		}
		while (pHead2)
		{
			if (s.find(pHead2) != s.end())
				return pHead2;
			pHead2 = pHead2->next;
		}
		return NULL;
	}
	//2.巧解
	//长度相同有公共结点，第一次就遍历到；没有公共结点，走到尾部NULL相遇，返回NULL
	//长度不同有公共结点，第一遍差值就出来了，第二遍一起到公共结点；没有公共，一起到结尾NULL。
	ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
		ListNode *p1 = pHead1;
		ListNode *p2 = pHead2;
		while (p1 != p2) {
			p1 = (p1 == NULL ? pHead2 : p1->next);
			p2 = (p2 == NULL ? pHead1 : p2->next);
		}
		return p1;
	}

	//3.让长度较长的先走,之后一起走
	//ListNode * FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
	//	if (pHead1 == NULL || pHead2 == NULL)
	//		return NULL;
	//	int size1 = 0;
	//	int size2 = 0;
	//	ListNode* cur = pHead1;

	//	while (cur)
	//	{
	//		//
	//		cur = cur->next;
	//		++size1;
	//	}
	//	cur = pHead2;
	//	while (cur)
	//	{
	//		cur = cur->next;
	//		++size2;
	//	}
	//	if (size1 > size2)
	//	{
	//		int count = size1 - size2;
	//		while (count--)
	//		{
	//			pHead1 = pHead1->next;
	//		}
	//	}
	//	else
	//	{
	//		int count = size2 - size1;
	//		while (count--)
	//		{
	//			pHead2 = pHead2->next;
	//		}
	//	}
	//	while (pHead1&&pHead2)
	//	{
	//		if (pHead1 == pHead2)
	//			return pHead1;
	//		pHead1 = pHead1->next;
	//		pHead2 = pHead2->next;

	//	}
	//	return NULL;
	//}
};