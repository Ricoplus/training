#include<iostream>
#include<vector>
using namespace std;

//��Ŀ����
//��һ���ַ���(1 <= �ַ������� <= 10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�, ����������λ��
class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		if (str.size() == 0)
			return -1;
		vector<int> v(256, 0);
		int i = 0;
		int size = (int)str.size();
		for (i = 0; i < size; i++)
			v[str[i]]++;
		for (i = 0; i < size; i++)
		{
			if (v[str[i]] == 1)
				return i;
		}
		return 0;
	}
};