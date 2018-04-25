#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//��Ŀ����
//����������������,��һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
//����ѹ��ջ���������־�����ȡ���������1, 2, 3, 4, 5��ĳջ��ѹ��˳��
//����4��5, 3, 2, 1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4, 3, 5, 1, 2�Ͳ������Ǹ�ѹջ���еĵ������С���
//ע�⣺���������еĳ�������ȵģ�
class Solution{
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		//1 2 3 4 5
		//4 5 3 2 1
		int i = 0, j = 0;
		stack<int> s;
		while (i<pushV.size())
		{
			s.push(pushV[i++]);
			while (!s.empty() && popV[j]==s.top())
			{
				s.pop();
				j++;
			}

		}
		return (s.size() == 0)?true : false;

		
	}
};