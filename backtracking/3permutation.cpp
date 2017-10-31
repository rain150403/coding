//输出不重复数字的全排列

#include <stdio.h>
#include <stdlib.h>
void rearr(int *arr,int a,int b)
{
    int i;
    int tmp = arr[b];
    for (i = b; i > a; i--)
        arr[i] = arr[i - 1];
    arr[a] = tmp;
}

void derearr(int *arr, int a, int b)
{
    int i;
    int tmp = arr[a];
    for (i = a; i <b; i++)
        arr[i] = arr[i + 1];
    arr[b] = tmp;
}

void perm(int *arr,int d,int N)
{
    int i;
    if (d > N)
    {
        for (i = 0; i <= N; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    else
    {
        for (i = d; i <= N; i++)
        {
            rearr(arr,d,i);
            perm(arr,d + 1, N);
            derearr(arr,d,i);
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    int *arr = (int *)malloc(N*sizeof(int));
    int i;
    for (i = 0; i < N; i++)
        arr[i] = i + 1;
    perm(arr,0,N-1);

    free(arr);
    return 0;
}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 205
using namespace std;

int len;
char s[N],ans[N];
int vis[N];

void dfs(int step)
{
    char ch = '\0';
    if (step == len)
    {
        puts(ans);
        return;
    }

    for (int i = 0; i < len; i++)
    {
        if (!vis[i] && ch != s[i])//后序在第i位放置的元素不能为ch。i位前的元素不重复不用考虑，因为s初始是升序的。
        {
            ans[step] = ch = s[i];//拷贝字符，ch保存当前全排列第i位置上的元素
            vis[i] = 1;
            dfs(step + 1);
            vis[i] = 0;
        }
    }
}

int main()
{
    while (~scanf("%s", s))
    {
        len = strlen(s);
        sort(s, s + len);//保证s是升序的

        dfs(0);
    }
    return 0;
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 205
using namespace std;

int len;
char s[N];

int main()
{
    gets(s);
    len = strlen(s);
    sort(s,s+len);
    do{
        puts(s);
    }while(next_permutation(s,s+len));
    return 0;
}

