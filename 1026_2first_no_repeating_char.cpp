/*
时间限制：1秒 空间限制：32768K
本题知识点： 字符串

题目描述
在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置
*/

//运行时间：2ms 占用内存：500k

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.size()==0)
            return -1;
        char ch[256]={0};
        for(int i=0;i<str.size();i++)
            ch[str[i]]++;
        for(int i=0;i<str.size();i++)
            if(ch[str[i]]==1)
                return i;
        return 0;
    }
};
