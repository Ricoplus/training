#include<iostream>
#include<vector>
using namespace std;
//��Ŀ����
//�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�
//����һ������, �����������е�����Ե�����P������P��1000000007ȡģ�Ľ������� �����P % 1000000007

//��������:
//��Ŀ��֤�����������û�е���ͬ������
//���ݷ�Χ��
//���� % 50������, size <= 10 ^ 4
//���� % 75������, size <= 10 ^ 5
//���� % 100������, size <= 2 * 10 ^ 5
class Solution{
public:
	int InversePairs(vector<int> v) {
		if(v.size()<=0)
			return 0;
		vector<int> tmp(v.size());
		long long count = 0;
		MergeSort(v,0,v.size()-1,tmp,count);
		return count%1000000007;
	}
	void MergeSort(vector<int>& a,int begin,int end,vector<int>& tmp,long long& count)
	{
		if(begin==end)
		{
			return;
		}
		int mid = begin +((end-begin)>>1);
		MergeSort(a,begin,mid,tmp,count);
		MergeSort(a,mid+1,end,tmp,count);
		int begin1 = begin,end1=mid;
		int begin2 = mid+1,end2=end;
		int index = begin;
		while(begin1<=end1&&begin2<=end2)
		{
			if(a[begin1]>=a[begin2])
			{
				tmp[index++] = a[begin1++];
				count += end2-begin2+1;
			}				
			else
			{
				tmp[index++] = a[begin2++];
			}
		}
		while(begin2<=end2)
			tmp[index++] = a[begin2++];
		
		while(begin1<=end1)
			tmp[index++] = a[begin1++];
		for (int i = begin; i <= end; i++)
		{
			a[i] = tmp[i];
		}
		return;
	}
};