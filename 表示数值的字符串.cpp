#include<iostream>
using namespace std;

//题目描述
//请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
//例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
// 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
class Solution {
public:
    //e后面不可以是小数
    bool isTrue(char* s)
    {
        if(*s=='\0')
            return false;
        if(*s=='+'||*s=='-')
            s++;
        while(*s)
        {
            if(*s>='0'&&*s<='9')
                s++;
            else
                return false;
        }
        return true;  
    }
    bool isNumeric(char* s)
    {
        if(s==NULL)
            return false;
        if(*s=='+'||*s=='-')
            s++;
        //标记小数点
        bool flag= false;
        while(*s)
        {
            if(*s>='0'&&*s<='9')
                s++;
            else if(*s=='E'||*s=='e')
            {
                return isTrue(s+1);
            }
            else if(flag==false&&*s=='.')
            {
                s++;
                flag=true;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

};