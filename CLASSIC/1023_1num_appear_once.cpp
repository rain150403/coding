/*
时间限制：1秒 空间限制：32768K
本题知识点： 数组

题目描述
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
*/

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
         
        int len=data.size();
        if(len<=2) return;
         
        int one=0;
        for(int i=0;i<len;i++)
        {
            one=one^data[i];
        }
         
        int pos=0;
        int flag=1;
        while(flag)
        {
            if(one&flag)
                break;
            flag=flag<<1;
            pos++;
        }
         
        for(int i=0;i<len;i++)
        {
            if((data[i]&flag)) *num1=*num1^data[i];
            else *num2=*num2^data[i];
        }
    }
     
};


/* 数组中唯一只出现一次的数字 
题目：在一个数组中除了一个数字只出现一次之外，其他数字都出现了三次。请找出那个吃出现一次的数字。*/

#include <cstdio>
#include <exception>

int FindNumberAppearingOnce(int numbers[], int length)
{
    if(numbers == nullptr || length <= 0)
        throw new std::exception("Invalid input.");

    int bitSum[32] = {0};
    for(int i = 0; i < length; ++i)
    {
        int bitMask = 1;
        for(int j = 31; j >= 0; --j)
        {
            int bit = numbers[i] & bitMask;
            if(bit != 0)
                bitSum[j] += 1;

            bitMask = bitMask << 1;
        }
    }

    int result = 0;
    for(int i = 0; i < 32; ++i)
    {
        result = result << 1;
        result += bitSum[i] % 3;
    }

    return result;
}
