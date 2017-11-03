//转自：http://www.cnblogs.com/dolphin0520/archive/2011/10/19/2217369.html

/*
 位图是一种很特殊的数据结构，可以利用位图来排序，但是这种排序方法对输入的数据是有比较严格的要求(数据不能重复，大致知道数据的范围)。举个例子，假如有一个集合{3,5,7,8,2,1}，我们可以用一个8位的二进制向量set[1-8]来表示该集合，如果数据存在，则将set相对应的二进制位置1，否则置0.根据给出的集合得到的set为{1,1,1,0,1,0,1,1}，然后再根据set集合的值输出对应的下标即可得到集合{3,5,7,8,2,1}的排序结果。

一.位图的应用：

      1.给40亿个不重复的unsigned int的整数，没有排过序，然后再给一个数，如果快速判断这个数是否在那40亿个数当中。

      因为unsigned int数据的最大范围在在40亿左右，40*10^8/1024*1024*8=476，因此只需申请512M的内存空间，每个bit位表示一个unsigned int。读入40亿个数，并设置相应的bit位为1.然后读取要查询的数，查看该bit是否为1，是1则存在，否则不存在。

      2.给40亿个unsigned int的整数，如何判断这40亿个数中哪些数重复？

      同理，可以申请512M的内存空间，然后读取40亿个整数，并且将相应的bit位置1。如果是第一次读取某个数据，则在将该bit位置1之前，此bit位必定是0；如果是第二次读取该数据，则可根据相应的bit位是否为1判断该数据是否重复。

二.位图的实现

     由于在C语言中没有bit这种数据类型，因此必须通过位操作来实现。

     假如有若干个不重复的正整数，范围在[1-100]之间，因此可以申请一个int数组，int数组大小为100/32+1。



假如有数据32，则应该将逻辑下标为32的二进制位置1，这个逻辑位置在A[1]的最低位(第0位)。

因此要进行置1位操作，必须先确定逻辑位置：字节位置(数组下标)和位位置。

字节位置=数据/32;(采用位运算即右移5位)

位位置=数据%32;(采用位运算即跟0X1F进行与操作)。

其他操作如清0和判断两个操作类似。
*/

// C语言

/*位图 2011.10.18*/ 
#include <stdio.h>
#define MAX 1000000
#define SHIFT 5           
#define MASK 0x1F
#define DIGITS 32
int a[1+MAX/DIGITS];

void set(int n)     //将逻辑位置为n的二进制位置为1 
{
    a[n>>SHIFT]=a[n>>SHIFT]|(1<<(n&MASK));     //n>>SHIFT右移5位相当于除以32求算字节位置，n&MASK相当于对32取余即求位位置，
}                                              //然后将1左移的结果与当前数组元素进行或操作，相当于将逻辑位置为n的二进制位置1.  

void clear(int n)
{
    a[n>>SHIFT]=a[n>>SHIFT]&(~(1<<(n&MASK)));   //将逻辑位置为n的二进制位置0，原理同set操作 
}

int test(int n)
{
    return a[n>>SHIFT] & (1<<(n&MASK));        //测试逻辑位置为n的二进制位是否为1 
}

int main(int argc, char *argv[])
{
    int i,n;
    for(i=1;i<=MAX;i++)
    {
        clear(i);
    }    
    while(scanf("%d",&n)!=EOF)
    {
        set(n);
    }
    for(i=1;i<=MAX;i++)
    {
        if(test(i))
            printf("%d ",i);
    }
    return 0;
}

//c++

/*位图C++STL实现 2011.10.19*/ 
#include <iostream>
#include<bitset> 
#define MAX 1000000
using namespace std;

bitset<MAX+1> bit;        //声明一个有(MAX+1)个二进制位的bitset集合，初始默认所有二进制位为0 

int main(int argc, char *argv[])
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        bit.set(n,1);          //将第n位置1               
    }    
    for(i=0;i<=MAX+1;i++)
    {
        if(bit[i]==1)
            printf("%d ",i);
    }
    return 0;
}
