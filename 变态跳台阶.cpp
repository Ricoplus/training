#include<iostream>

using namespace std;
//��Ŀ����
//һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������


//ÿ��̨�׶������벻������������������һ��̨�ף������һ��̨�ױ����������Թ���2^(n-1)����� 
	class Solution {
	public:
		int jumpFloorII(int number) {
		
			return number<<(number-1);
		}
	};