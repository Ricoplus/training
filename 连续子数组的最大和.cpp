#include<iostream>
#include<vector>
using namespace std;
//��Ŀ����
//HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ����������鿪����, 
//���ַ�����:�ڹ��ϵ�һάģʽʶ����, ������Ҫ��������������������, ��
//����ȫΪ������ʱ��, ����ܺý��������, ��������а�������, �Ƿ�
//Ӧ�ð���ĳ������, �������Աߵ��������ֲ����أ�
//���� : {6, -3, -2, 7, -15, 1, 2, 2}, ����������������Ϊ8(�ӵ�0����ʼ, ����3��Ϊֹ)��
//��᲻�ᱻ������ס��(�������ĳ���������1)

//��һ�������ȷ ����ۻ��ͱ���Ǹ��� �Ŷ���������дٽ����õ�,����Ǹ���,����Ϊ�к����ܺͣ�����total
//������max,���¼��max��
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.size() == 0)
			return 0;

		int max = array[0], total = array[0];
		//��1��ʼ
		for (size_t i = 1; i < array.size(); i++)
		{
			if (total > 0)
			{
				total += array[i];
			}
			else
			{
				total = array[i];
			}
			if (total > max)
				max = total;
		}
		return max;

	}
};