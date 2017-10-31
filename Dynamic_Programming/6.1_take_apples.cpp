/*
问题描述

平面上有N*M个格子，每个格子中放着一定数量的苹果。你从左上角的格子开始，每一步只能向下走或是向右走，每次走到一个格子上就把格子里的苹果收集起来，这样下去，你最多能收集到多少个苹果。
输入：
第一行输入行数和列数
然后逐行输入每个格子的中的苹果的数量
输出：
最多能收到的苹果的个数。

思路分析

这是一个典型的二维数组DP问题
基本状态：
当你到达第x行第y列的格子的时候，收集到的苹果的数量dp[x][y]。
转移方程：
由于你只能向右走或者向下走，所以当你到达第x行第y列的格子的时候，你可能是从第x-1行第y列或者第x行第y-1列到达该格子的，而我们最后只要收集苹果最多的那一种方案。
所以：
dp[x][y] = max( if(x>0) dp[x-1][y] , if(y>0) dp[x][y-1])
*/

#include<iostream>  
#include<string.h>  
using namespace std;  
int a[100][100];  
int dp[100][100];  
int m,n;  
  
void dp_fun(int x,int y)  
{  
    dp[x][y] = a[x][y];  
    int max = 0;  
    if(x > 0 && max < dp[x-1][y])  
    {  
        max = dp[x-1][y];  
    }  
    if(y > 0 && max < dp[x][y-1])  
    {  
        max = dp[x][y-1];  
    }  
    dp[x][y] += max;  
    if(x<m-1)  
    {  
        dp_fun(x+1,y);  
    }     
    if(y<n-1)  
    {  
        dp_fun(x,y+1);  
    }  
    return;  
}   
  
int main()  
{  
    memset(dp,0,sizeof(dp));   
    cin>>m>>n;  
    for(int i=0;i<m;i++)  
    {  
        for(int j=0;j<n;j++)  
        {  
            cin>>a[i][j];  
        }  
    }     
    dp_fun(0,0);  
    for(int i=0;i<m;i++)  
    {  
        for(int j=0;j<n;j++)  
        {  
            cout<<dp[i][j]<<"\t";  
        }  
        cout<<endl;  
    }  
    return 0;  
}  
