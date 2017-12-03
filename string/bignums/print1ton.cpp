/*
输入数字n， 按顺序打印出从1到最大的n位十进制数。比如输入3， 则打印出1，2，3，一直到最大的3位数即999

    全排列递归实现方法：
    数字的每一位都可能是0-9中的一个位数，我们把数字的每一位都从0到9排列一边，就得到了所有的十进制数，全排列用递归很容易表达，数字的每一位都可能是一个
    数，然后设置下一位。这里递归结束的条件是我们已经设置了数字的最后一位。
*/

#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
#include<stdbool.h>  
/* 
打印字符数表示的数字，要跳过前面的'0' 
*/  
void PrintNum(char *num)  
{  
    int i = 0;  
    while(num[i] == '0')  
        i++;  
    puts(num+i);  
}  
  
/* 
递归设置从index位往右的各位数字，并打印出来 
*/  
void RecursionPrint1ToN(char *num,int len,int index)  
{  
    if(index == len)  
    {  
        PrintNum(num);  
        return;  
    }  
    int i;  
    for(i=0;i<10;i++)  
    {  
        num[index] = i + '0';  
        RecursionPrint1ToN(num,len,index+1);  
    }  
}  
  
/* 
打印从1到最大的n位数 
*/  
void Print1ToMaxN(int n)  
{  
    if(n<=0)  
        return;  
  
    char *num = (char *)malloc((n+1)*sizeof(char));  
    if(num == NULL)  
        exit(EXIT_FAILURE);  
    //每个字节都初始化为'0'字符  
    memset(num,'0',n*sizeof(char));  
    num[n] = '\0';  
      
    //全部打印出来  
    RecursionPrint1ToN(num,n,0);  
  
    free(num);  
    num = NULL;  
}  
  
int main()  
{  
    int n;  
    scanf("%d",&n);  
    Print1ToMaxN(n);  
    return 0;  
}  
