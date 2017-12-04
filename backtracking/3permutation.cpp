//输出不重复数字的全排列

//首先是《玩转算法。。。》里面的解法
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<bool> used;

    // p中保存了一个有index-1个元素的排列。
    // 向这个排列的末尾添加第index个元素, 获得一个有index个元素的排列
    void generatePermutation( const vector<int>& nums, int index, vector<int>& p){

        if( index == nums.size() ){
            res.push_back(p);
            return;
        }

        for( int i = 0 ; i < nums.size() ; i ++ )
            if( !used[i] ){
                used[i] = true;
                p.push_back( nums[i] );
                generatePermutation(nums, index+1, p );
                p.pop_back();
                used[i] = false;
            }

        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {

        res.clear();
        if( nums.size() == 0 )
            return res;

        used = vector<bool>(nums.size(), false);
        vector<int> p;
        generatePermutation( nums, 0, p );

        return res;
    }
};

int main() {

    int nums[] = {1, 2, 3};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int) );

    vector< vector<int> > res = Solution().permute(vec);
    for( int i = 0 ; i < res.size() ; i ++ ){

        for( int j = 0 ; j < res[i].size() ; j ++ )
            cout<<res[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
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

