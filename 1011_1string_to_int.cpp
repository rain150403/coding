/*
时间限制：1秒 空间限制：32768K 
本题知识点： 字符串

题目描述
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
输入描述:
输入一个字符串,包括数字字母符号,可以为空
输出描述:
如果是合法的数值表达则返回该数字，否则返回0
示例1
输入

+2147483647
    1a33
输出

2147483647
    0
*/

//运行时间：3ms 占用内存：500K


//不能理解，多看看
class Solution {
public:
    int StrToInt(string str) {
        long long result = 0;
        string tempStr = str;
        int spcNum = 0;
        for (const auto ch : str)
        {
            if (' ' == ch)
                ++spcNum;
            else
                break;
        }
        if ('+' == str[spcNum] || '-' == str[spcNum])
            tempStr = str.substr(spcNum + 1, str.size() - spcNum - 1);
        else
            tempStr = str.substr(spcNum, str.size() - spcNum);
        for (const auto ch : tempStr)
        {
            if (ch < '0' || ch > '9')
                return 0;
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && ch - '0' > 7))     //这个判断溢出的条件是最头疼的
            {
                if ('-' == str[spcNum])
                    return INT_MIN;
                else
                    return INT_MAX;
            }
            if (ch == ' ')
                break;
            result = result * 10 + (ch - 48);
        }
        ('-' == str[spcNum]) ? result *= -1 : result *= 1;
 
        return result;
    }
};
