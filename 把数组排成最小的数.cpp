#include<iostream>
#include<vector>
#include<string>
using namespace std;
//��Ŀ����
//����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
//������������{ 3��32��321 }�����ӡ���������������ųɵ���С����Ϊ321323��
class Solution {
public:
	struct Com{
		bool operator()(int a, int b) const
		{
			string A = to_string(a) + to_string(b);
			string B = to_string(b) + to_string(a);
			return A < B;
		}
	};

	/*��vector�����ڵ����ݽ������򣬰��� ��a��bתΪstring��
	�� a��b<b+a  a������ǰ �Ĺ�������,
	�� 2 21 ��Ϊ 212 < 221 ���� �����Ϊ 21 2
	to_string() ���Խ�int ת��Ϊstring
	*/
	string PrintMinNumber(vector<int> numbers){
		
		//�����compû������
		sort(numbers.begin(), numbers.end(), Com);
		string s;
		for (size_t i = 0; i < numbers.size(); i++)
		{
			s += to_string(numbers[i]);
		}
		return s;
	}
};