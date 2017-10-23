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
