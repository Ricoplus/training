#include<iostream>
#include<vector>
using namespace std;
//题目描述
//HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后, 
//他又发话了:在古老的一维模式识别中, 常常需要计算连续子向量的最大和, 当
//向量全为正数的时候, 问题很好解决。但是, 如果向量中包含负数, 是否
//应该包含某个负数, 并期望旁边的正数会弥补它呢？
//例如 : {6, -3, -2, 7, -15, 1, 2, 2}, 连续子向量的最大和为8(从第0个开始, 到第3个为止)。
//你会不会被他忽悠住？(子向量的长度至少是1)

//有一点必须明确 左边累积和必须非负数 才对整体和是有促进作用的,如果是负数,则认为有害于总和，换掉total
//若大于max,则记录在max中
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.size() == 0)
			return 0;

		int max = array[0], total = array[0];
		//从1开始
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