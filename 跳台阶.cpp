//��Ŀ����
//һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж�����������


//�ҹ��ɵĽⷨ��f(1) = 1, f(2) = 2, f(3) = 3, f(4) = 5��  �����ܽ��f(n) = f(n-1) + f(n-2)
class Solution {
public:
	int jumpFloor(int n) {
		if (n <= 0)
			return 0;
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;
		//�ݹ�
		return jumpFloor(n - 1)+ jumpFloor(n - 2);
		//�ǵݹ�
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