#include<iostream>
#include<vector>
using namespace std;


//��Ŀ����
//����һ���ַ���, ���ֵ����ӡ�����ַ������ַ����������С����������ַ���abc, ���ӡ�����ַ�a, b, c�������г����������ַ���abc, acb, bac, bca, cab��cba��
class Solution {
	vector<string> v;
public:
	void Per(string& str, int begin)
	{
		if (str[begin] == '\0')
		{
			v.push_back(str);
			return;
		}
		for (int i = begin; i < str.size(); i++)
		{
			if (begin != i && str[begin] == str[i])
				continue;
			swap(str[begin], str[i]);
			Per(str, begin + 1);
			swap(str[begin], str[i]);
		}
	}
	vector<string> Permutation(string str){
		if (str.size() == 0)
			return v;
		Per(str, 0);
		sort(v.begin(), v.end());
		return v;
	}
};