//电话号码对应字符串

//电话键盘上有9个数字，其中2~9分别代表了几个字母，如2:ABC，3:DEF......等等。给定一个数字序列，输出它所对应的所有字母序列。

/* 
电话号码对应英语单词: 
电话的号码盘一般可以用于输入字母。如用2可以输入A,B,C，用3可以输入D,E,F等。 
对于号码5869872,可以依次输出其代表的所有字母组合。例如:JTMWTPA,JTMWTPB... 
1您是否可以根据这样的对应关系设计一个程序，尽可能快地从这些字母组合中找到一个由意义的单词来表述一个电话号码呢?如:可以用单词"computer" 
来描述号码26678837 
2对于一个电话号码，是否可以用一个单词来代表呢？怎样才是最快的方法呢？显然，肯定不是所有的电话号码都能够对应到单词上去。但是根据问题1的解答，思路 
比较清晰。 
 
分析: 
除了0,1之外，其他数字上最少都有3个字符，其中7,9上有4个字符，我们假设0,1输出的是空字符。 
首先，将问题简单化。若电话号码只有1位数，比如说4，那么其代表的“单词”为G、H、I，据此可以画出一颗排列树。 
若电话号码升级到两位数，比如42，分两步走。从左到右，在选择一个第一位数字代表的字符的基础上，遍历第二位数字代表的字符，知道遍历完第一位数字代表的 
所有字符。 
                                                            42 
                4                     G                     H                          I 
                2             A       B       C       A     B       C       A          B             C 
 
通过遍历这棵排列数所有叶子结点而得到的所有路径的集合，即为42所能代表的所有单词的集合。 
如何遍历得到电话号码所能代表的单词集合? 
 
问题1解法1:直接循环法 
将各个数字所能代表的字符存储在一个二维数组中，其中假设0,1所代表的字符为空字符，并将各个数字所能代表的字符总数记录于另一个数组中： 
 
 
问题1的解法2:递归的方法: 
可以将每层的for循环看成一个递归函数的调用 
 
问题2的解法1： 
把改电话对应的字符全部统计出来，然后匹配字典，判断是否有答案。 
 
问题2的解法2: 
如果查询次数较多，可以把字典里面所有单词转换为数字，存到文件中，使之成为一本数字字典，然后对这个电话号码查表得到结果。 
 
输入: 
2 
4 2 
输出: 
GA 
GB  
GC  
HA 
HB 
HC 
IA 
IB 
IC 
*/  
  
/* 
关键: 
1 char g_numToWord[10][10] = //牛逼，用二维数组来建立数字到字符串的映射 
{ 
    "", 
    "", 
    "ABC", 
2 int g_numToWordNum[10] = {0,0,3,3,3,3,3,4,3,4};//将各个数字所能代表的字符总数记录于另一个数组中 
3   int k = n -1 ; //确保每次从后向前遍历 
        while(k >= 0) 
        { 
            if(answer[k] < g_numToWordNum[number[k]] - 1)//这个是用来保证最多answer[k] = g... - 1, 
            { 
                answer[k]++;//累加位置，为遍历当前字母下一位做准备 
                break;//跳出的目的是为了进行下一轮打印 
            } 
            else 
            { 
                answer[k] = 0;//如果已经达到当前数字打印的最后一位，那么重新归零，k--会对当前数字前面的一个数字进行打印 
                k--; 
            } 
        } 
        if(k < 0)//说明所有的数字全部打印结束 
        { 
            break; 
4 void telephoneToWord_recursion(int* number,int* answer,int n,int iPos)//递推的结果参见刘汝佳关于全排列，素数环的算法，用iPos 
5       for(answer[iPos] = 0 ; answer[iPos] < g_numToWordNum[number[iPos] ] ; answer[iPos]++)//关键:递归这里先打印的是后面的再打印前面的 
        { 
            telephoneToWord_recursion(number,answer,n,iPos+1); 
*/  


#include <stdio.h>
#include <string.h>
const int MAXSIZE = 100;
char g_numToWord[10][10] = //牛逼，用二维数组来建立数字到字符串的映射
        {
                "",   //0
                "",   //1
                "ABC",   //2
                "DEF",  //3
                "GHI",  //4
                "JKL",   //5
                "MNO",  //6
                "PQRS",   //7
                "TUV",   //8
                "WXYZ"   //9
        };

int g_numToWordNum[10] = {0,0,3,3,3,3,3,4,3,4};//将各个数字所能代表的字符总数记录于另一个数组中

void telephoneToWord_while(int* number,int* answer,int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&number[i]);
    }
    while(true)
    {
        for(int i = 0 ; i < n ; i++)
        {
            printf("%c",g_numToWord[ number[i] ][ answer[i] ]);
        }
        printf("\n");
        int k = n -1 ; //确保每次从后向前遍历
        while(k >= 0)
        {
            if(answer[k] < g_numToWordNum[number[k]] - 1)//这个是用来保证最多answer[k] = g... - 1,
            {
                answer[k]++;//累加位置，为遍历当前字母下一位做准备
                break;//跳出的目的是为了进行下一轮打印
            }
            else
            {
                answer[k] = 0;//如果已经达到当前数字打印的最后一位，那么重新归零，k--会对当前数字前面的一个数字进行打印
                k--;
            }
        }
        if(k < 0)//说明所有的数字全部打印结束
        {
            break;
        }
    }
}

void telephoneToWord_recursion(int* number,int* answer,int n,int iPos)//递推的结果参见刘汝佳关于全排列，素数环的算法，用iPos
{
    if(iPos == n)//递归出口
    {
        for(int i = 0 ; i < n ; i++)
        {
            printf("%c",g_numToWord[ number[i] ][ answer[i] ]);
        }
        printf("\n");
    }
    else
    {
        for(answer[iPos] = 0 ; answer[iPos] < g_numToWordNum[number[iPos] ] ; answer[iPos]++)//关键:递归这里先打印的是后面的再打印前面的
        {
            telephoneToWord_recursion(number,answer,n,iPos+1);
        }
    }
}

void process()
{
    int n;
    while(EOF != scanf("%d",&n))
    {
        int number[MAXSIZE];//用一个数组存储电话号码
        int answer[MAXSIZE];//将数字目前所代表的字符在其所能代表的字符集中的位置用一个数组储存起来
        memset(answer,0,sizeof(answer));
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d",&number[i]);
        }
        //telephoneToWord_while(number,answer,n);
        int iPos = 0;
        telephoneToWord_recursion(number,answer,n,iPos);
    }
}

int main(int argc,char* argv[])
{
    process();
    getchar();
    return 0;
}

//the first number means: number of numbers; then followed with the numbers, take care , no 0, 1.
