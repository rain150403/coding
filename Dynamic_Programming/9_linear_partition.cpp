/*
工作量划分
难度评级：★★

　　假设书架上一共有9本书，每本书各有一定的页数，分配3个人来进行阅读。为了便于管理，分配时，各书要求保持连续，比如第1、2、3本书分配给第1人，4、5分配给第二人，6，7，8，9分配给第3人，但不能1，4，2分配给第1人，3，5，6分配给第2人。即用两个隔板插入8个空隙中将9本书分成3部分，书不能换位。同时，分配时必须整本分配，同一本书不能拆成两部分分给两个人。为了公平起见，需要将工作量最大的那一部分最小化，请设计分配方案。用s1,...,sn表示各本书的页数。

解法：

　　继续从子结构的角度出发，发现如果前面的k-1份已经分好了，那么第k份自然也就分好了。用M[n][k]表示将n本书分成k份时最小化的k份中的最大工作量，从第k份也就是最后一份的角度来看，总数-它的不同情况下数量 = 前k-1份的数量和。


M[n][k] = \overset{n}{\underset{i=1}{min}}\max(M[i][k-1],\sum_{j=i+1}^{n}s_{j})
 　　除此以外，初始化为


M[1][k] = s_{1},for \ all \ k>0\\ M[n][1] = \sum_{i=1}^{n}s_{1}
　　自底向上地可以求得使M[n][k]最小化的解。
*/

//这个问题被称为线性分割(linear partition)问题，有不少的应用情形。如，一系列任务分配给几个并行进程，那么分配工作量最大任务的那个进程将成为影响最终
//完成时间的瓶颈。将最大的工作量尽量减少，能够使所有工作更快地完成。

#include <stdio.h>
#define MAXN 9
#define MAXINT 32767

void print_books(int s[],int start,int end);
int reconstruct_partition(int s[],int d[MAXN+1][MAXN+1],int n,int k);
int max(int a,int b);

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int partition(int s[],int n,int k)
{
    int m[MAXN+1][MAXN+1];
    int d[MAXN+1][MAXN+1];
    int p[MAXN+1];
    int cost;
    int i,j,x;

    p[0] = 0;
    for(i=1;i<=n;i++)
        p[i] = p[i-1]+s[i-1];
    for(i=1;i<=n;i++)
        m[i][1] = p[i];
    for(j=1;j<=k;j++)
        m[1][j] = s[0];
    for(i=2;i<=n;i++)
        for(j=2;j<=k;j++)
        {
            m[i][j] = MAXINT;
            for(x=1;x<=(i-1);x++) 
            {
                cost = max(m[x][j-1],p[i]-p[x]);
                if(m[i][j]>cost) {
                    m[i][j] = cost;
                    d[i][j] = x;
                }
            }
        }
    reconstruct_partition(s,d,n,k);
}

int reconstruct_partition(int s[],int d[MAXN+1][MAXN+1],int n,int k)
{
    if(k==1)
        print_books(s,1,n);
    else
    {
        reconstruct_partition(s,d,d[n][k],k-1);
        print_books(s,d[n][k]+1,n);
    }
    return 0;
}

void print_books(int s[],int start,int end)
{
    int i;
    for(i=start;i<=end;i++)
        printf(" %d ",s[i-1]);
    printf("\n");
    return;
}

int main() {
    int a[] = {1,1,1,1,1,1,1,1,1};
    int b[] = {1,2,3,4,5,6,7,8,9};
    printf("first:\n");
    partition(a,9,3);
    printf("\nsecond:\n");
    partition(b,9,3);
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////

/*
转自：http://www.cnblogs.com/mengwang024/p/4342796.html
钢条切割问题
*/


#include <iostream>
using namespace std;

void ExtendedBUCutRod(const int *p, int n, int *r, int *s)
{
    r[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int q = -1;
        for (int j = 1; j <= i; ++j)
        {
            int tmp = p[j - 1] + r[i - j];
            if (q < tmp)
            {
                q = tmp;
                s[i] = j;
            }
        }
        r[i] = q;
    }
}

//r[]保存长度为i的钢条最大收益,s[]保存最优解对应的第一段钢条的切割长度
void PrintBUCutRod(const int *p, int n, int *r, int *s)
{
    ExtendedBUCutRod(p, n, r, s);
    cout << "长度为" << n << "的钢条最大收益为:" << r[n] << endl;

    cout << "最优方案的钢条长度分别为:";
    while (n > 0)
    {
        cout << s[n] << " ";
        n = n - s[n];
    }
    cout << endl;
}

//Test
int main()
{
    int n;
    while (cin >> n)
    {
        int *p = new int[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> p[i];
        }
        int *r = new int[n + 1];
        int *s = new int[n + 1];

        PrintBUCutRod(p, n, r, s);
    }

    return 0;
}
