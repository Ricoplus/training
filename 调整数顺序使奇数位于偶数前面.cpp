#include<iostream>
#include<vector>
using namespace std;



//��Ŀ����
//����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿��
//���е�ż��λ��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣



class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int> v;
		for (size_t i = 0; i < array.size(); i++)
		{
			if (array[i] % 2 != 0)
				v.push_back(array[i]);
		}
		for (size_t i = 0; i < array.size(); i++)
		{
			if (array[i] % 2 == 0)
				v.push_back(array[i]);
		}
		v.swap(array);
	}
};