#include<iostream>
#include<vector>
#include<set>
using namespace std;

//��Ŀ����
//�������������ҳ����ǵĵ�һ��������㡣

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
	//2.�ɽ�
	//������ͬ�й�����㣬��һ�ξͱ�������û�й�����㣬�ߵ�β��NULL����������NULL
	//���Ȳ�ͬ�й�����㣬��һ���ֵ�ͳ����ˣ��ڶ���һ�𵽹�����㣻û�й�����һ�𵽽�βNULL��
	ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
		ListNode *p1 = pHead1;
		ListNode *p2 = pHead2;
		while (p1 != p2) {
			p1 = (p1 == NULL ? pHead2 : p1->next);
			p2 = (p2 == NULL ? pHead1 : p2->next);
		}
		return p1;
	}

	//3.�ó��Ƚϳ�������,֮��һ����
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