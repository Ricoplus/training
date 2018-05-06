#include<iostream>
#include<vector>
using namespace std;
//题目描述
//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
//输入一个数组, 求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P % 1000000007

//输入描述:
//题目保证输入的数组中没有的相同的数字
//数据范围：
//对于 % 50的数据, size <= 10 ^ 4
//对于 % 75的数据, size <= 10 ^ 5
//对于 % 100的数据, size <= 2 * 10 ^ 5
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