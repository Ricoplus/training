//��Ŀ����
//��ʵ��һ����������һ���ַ����еĿո��滻�ɡ� %20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��



class Solution {
public:
	void replaceSpace(char *str, int length) {

		int spacenum = 0;
		int oldlength = 0;
		for (size_t i = 0; str[i]!='\0'; i++)
		{
			if (str[i] == ' ')
				spacenum++;
			oldlength++;
		}
		//��Ϊ�С�\0�� ���������1
		int newlength = oldlength + 2 * spacenum;

		if (newlength > length)
			return;
		while (oldlength>=0)
		{
			if (str[oldlength] == ' ')
			{
				str[newlength--] = '0';
				str[newlength--] = '2';
				str[newlength--] = '%';

			}
			else
				str[newlength--] = str[oldlength];
			oldlength--;
		}
	}
};

