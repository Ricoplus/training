#include<iostream>

using namespace std;
//题目描述
//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。


//每个台阶都有跳与不跳两种情况（除了最后一个台阶），最后一个台阶必须跳。所以共用2^(n-1)中情况 
	class Solution {
	public:
		int jumpFloorII(int number) {
		
			return number<<(number-1);
		}
	};