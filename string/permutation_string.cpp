/*
题目描述： 
输入一个字符串，打印出该字符串中字符的所有排列。 
基本思路： 
从字符串中选出一个字符作为排列的第一个字符，然后对剩余的字符进行全排列，如此递归，从而得到所有字符的全排列。以对字符”abc”进行全排列为例，可以按下述
步骤执行： 
将a固定在第一位，求后面bc的排列 
将b固定在第一位，求后面ac的排列 
将c固定在第一位，求后面ab的排列
*/

#include<stdio.h>
#include<stdlib.h>
#define swap(t,x,y) (t = (x),x = (y),y = (t))
void CalcAllPermutation(char *perm,int from,int to)
{
    if (to < 0)
        return ;
    int i = 0;
    char t;
    if (from == to)
    {
        for (i = 0;i <= to;i++)
            printf("%c",perm[i]);
        printf("\n");
    }
    else
    {
        for (i = from;i <= to;i++)
        {
            swap(t,perm[i],perm[from]);//将from-to中的一个元素固定在第一位
            CalcAllPermutation(perm,from+1,to);
            swap(t,perm[i],perm[from]);//恢复以前的状态
        }
    }
}
int main()
{
    char s[] = "abcd";
    CalcAllPermutation(s,0,3);
    return 0;
}
