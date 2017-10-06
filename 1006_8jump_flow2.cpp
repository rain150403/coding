/*
时间限制：1秒 空间限制：32768K 热度指数：127427

题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/

/*
因为n级台阶，第一步有n种跳法：跳1级、跳2级、到跳n级
跳1级，剩下n-1级，则剩下跳法是f(n-1)
跳2级，剩下n-2级，则剩下跳法是f(n-2)
所以f(n)=f(n-1)+f(n-2)+...+f(1)
因为f(n-1)=f(n-2)+f(n-3)+...+f(1)
所以f(n)=2*f(n-1)
*/

//运行时间：1ms， 占用内存：500K

class Solution {
public:
    int jumpFloorII(int number) {
        if(number==0)
            return number;
        int total=1;
        for(int i=1;i<number;i++)
            total*=2;
        return total;
    }
};
