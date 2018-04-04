//题目描述
//请实现一个函数，将一个字符串中的空格替换成“ %20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。



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
		//因为有‘\0’ 所以无需减1
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

