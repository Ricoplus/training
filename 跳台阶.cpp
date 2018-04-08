//题目描述
//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。


//找规律的解法，f(1) = 1, f(2) = 2, f(3) = 3, f(4) = 5，  可以总结出f(n) = f(n-1) + f(n-2)
class Solution {
public:
	int jumpFloor(int n) {
		if (n <= 0)
			return 0;
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;
		//递归
		return jumpFloor(n - 1)+ jumpFloor(n - 2);
		//非递归
		/*int first = 1, second = 2, third = 0;
		for (int i = 3; i <=n; i++)
		{
			third = first + second;
			first = second;
			second = third;
		}
		return third;*/
		
	}
};