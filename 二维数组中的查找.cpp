//��Ŀ����
//��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
//�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������

#include<iostream>
using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > v) {
		int i = v.size()-1, j = 0;
		while (i >= 0 && j < v[0].size()-1)
		{
			if (target == v[i][j])
				return true;

			if (target > v[i][j])
				j++;
			else
				i--;

		}
		return false;
	}
};