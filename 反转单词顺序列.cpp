#include<iostream>
#include<vector>
#include<string>
using namespace std;
// 题目描述
// 牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
//同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
//例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
//正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

//1.利用string
// class Solution {
// public:
// 	string ReverseSentence(string str) {
// 		vector<string> tmp;
// 		string t;
// 		for (size_t i = 0; i<str.size(); i++) {
// 			if (str[i] == ' ')
// 			{
// 				tmp.push_back(t);
// 				t.clear();
// 			}
// 			else
// 			{
// 				t += str[i];
// 			}
			
// 		}
// 		tmp.push_back(t);
// 		string s;
// 		for (int i = tmp.size() - 1; i>0; i--)
// 		{
// 			s += tmp[i];
// 			s += " ";
// 		}
// 		s += tmp[0];
// 		return s;
// 	}
// };

//2.
class Solution {
public:
    void Reverse(string& str,int left,int right)
    {
        while(left<right)
        {
            swap(str[left++],str[right--]);
        }
    }
    string ReverseSentence(string str) {
        if(str.size()==0)
            return str;
        Reverse(str,0,str.size()-1);
        int start = 0;
        int end = 0;
        for(end = 0;end<str.size();end++)
        {
            if(str[end]==' ')
            {
                Reverse(str,start,end-1);
                start = end+1;
            }
        }
        Reverse(str,start,end-1);
        return str;
    }
};