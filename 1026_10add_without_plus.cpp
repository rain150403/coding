/*
时间限制：1秒 空间限制：32768K

题目描述
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号
*/

//运行时间：2ms 占用内存：496k

class Solution {
public:
    int Add(int num1, int num2)
    {
        int sum, carry;
        do{
            sum = num1 ^ num2;
            carry = ( num1 & num2 ) << 1;
            
            num1 = sum;
            num2 = carry;
        }
        while( num2 != 0 );
        
        return num1;
    }
};
