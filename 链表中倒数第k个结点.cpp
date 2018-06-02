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
	ListNode * FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (k == 0 || pListHead == NULL)
			return NULL;
		
		ListNode* cur = pListHead;
		//�������ڵ�����������һ���������� ֱ�ӻ᷵�ؿ� ����--k ����k--
		while (--k)
		{
			cur = cur->next;
			if (cur == NULL)
				return NULL;
		}
		while (cur->next)
		{
			pListHead = pListHead->next;
			cur = cur->next;
		}
		return pListHead;
	}
};