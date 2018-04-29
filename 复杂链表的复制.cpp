#include<iostream>
using namespace std;


//��Ŀ����
//����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩��
//���ؽ��Ϊ���ƺ��������head����ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�



struct RandomListNode{
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) 
		:label(x)
		,next(NULL)
		,random(NULL) 
	{}
};

class Solution {
public:
	/*
	1������ÿ���ڵ㣬�磺���ƽڵ�A�õ�A1����A1����ڵ�A����
	2����������A1->random = A->random->next;
	3���������ֳ�ԭ����͸��ƺ������
	*/

	RandomListNode* Clone(RandomListNode* pHead)
	{
		//�տ�ʼ��û��random ������Ҫ������
		if (!pHead) return NULL;
		RandomListNode *currNode = pHead;
		while (currNode) {
			RandomListNode *node = new RandomListNode(currNode->label);
			node->next = currNode->next;
			currNode->next = node;
			currNode = node->next;
		}
		currNode = pHead;
		while (currNode) {
			RandomListNode *node = currNode->next;//ע���¸���������ʵ��2��4��6��8
			if (currNode->random) {
				node->random = currNode->random->next;
			}
			currNode = node->next;
		}
		//���
		RandomListNode *pCloneHead = pHead->next;
		RandomListNode *tmp;
		currNode = pHead;
		//2 4
	
		while (currNode->next){
			tmp = currNode->next;//2�ڵ����
			currNode->next = tmp->next;//1��3��������
			currNode = tmp;//2   
			//3 �ڵ������
			//2��4��������
			//3
		}
		return pCloneHead;
	}
};