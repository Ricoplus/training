#include<iostream>
#include<vector>
using namespace std;

//��Ŀ����
//����һ����������������е�����k����㡣


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) 
		:val(x)
		,next(NULL)
	{}
};
//������һ��K���ȵĳ���, �ѳ��Ӵ�ͷ�����ƶ�, �����ӵ��Ҷ��������ĩβ�����ʱ�򣬳���������ڵĽ����ǵ�����k����㣡
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL || k < 0)
			return NULL;

		ListNode* pre = pListHead;
		ListNode* last = pListHead;
		while (k--)
		{
			last = last->next;
			if (last==NULL)
				return NULL;
		}
		while (last->next)
		{
			pre = pre->next;
			last = last->next;
		}
		return pre;
		/*if (pListHead == NULL)
			return NULL;
		vector<ListNode*> v;
		ListNode* cur = pListHead;
		while (cur)
		{
			v.push_back(cur);
			cur = cur->next;
		}
		if (v.size() - k >= v.size())
			return NULL;
		return v[v.size() - k];*/
	}
};
