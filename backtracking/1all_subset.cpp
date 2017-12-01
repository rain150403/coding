//这一节的内容各种问题，哎
http://www.cnblogs.com/grandyang/p/4820842.html
http://www.cnblogs.com/felixfang/p/3775712.html

//求一个集合的所有子集问题

/*生成子集的三种方式：

2)二进制位变换
3)格雷码。
1)按排序生成 (按排序生成则比较复杂，它按特定顺序生成,除非有这种要求，否则不要使用这个方式)*/

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
/*
　　一间能容纳n个人的空房，房外有n个人。你站在门口，可以选择让门外的一个人进屋，也可以选择让屋内的人出来一个。请输出所有的2n种屋中人的出现情况的可能，并且这些情况是相邻的（上一种情况通过一次操作能变成下一种情况）

解答：

　　一开始不是很理解，参考答案上也提到是用格雷码来解决。不过如果知道格雷码的生成方式，就好解决了：

        1位格雷码有两个码字
        (n+1)位格雷码中的前2n个码字等于n位格雷码的码字，按顺序书写，加前缀0
        (n+1)位格雷码中的前2n个码字等于n位格雷码的码字，按逆序书写，加前缀1

 

　　不过为了输出美观，由于C语言不提供printf直接输出2进制数，需要把10进制数转化成2进制数输出，而且首端的0要补上，这需要花点心思。下面是一个生成4位格雷码的程序，并不是回溯法。（为了省事直接在回溯法框架上改的）
*/

/*
上面的例子完全看不出和本节的代码有什么关系，
其次，下面的“二进制位变换”是否能够work，并没有给finished终止条件赋值的地方，并且是否应该给K一个递增的过程，让其能够求出所有子集，最后，这是一个
递归过程，我不是很理解。容易晕。当然，在construct candidates的时候，很巧妙。
*/

//按排序生成 (按排序生成则比较复杂，它按特定顺序生成,除非有这种要求，否则不要使用这个方式)*/

/*虽然复杂，但这是最容易理解的，并且能输出正确结果的一个代码*/
#include <stdio.h>

int main(int argc,char **argv){
    int n,i,runner,start,end;
    printf("请输入正整数的n的值：");
    scanf("%d",&n);
    printf("{}\n"); //输出空集
    for(end = 1; end <= n; end++){
        printf("{%d}\n",end);
        for(start = end; start > 0; start--){
            for(runner = 1; runner < start; runner++){
                printf("{");
                printf("%d",runner);
                for(i = start; i < end; i++){
                    printf("%d",i);
                }
                printf("%d}\n",end);
            }
        }
    }
}


^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


//二进制位变换

#include <stdio.h>

#define NMAX 100000
#define MAXCANDIDATES 100000

int is_a_solution(int a[],int k, int input)
{
    return k==input;
}

void construct_candidates(int a[],int k, int input, int c[],int *ncandidates)
{
    c[0] = 1;
    c[1] = 0;
    *ncandidates = 2;
}

void process_solution(int a[],int k,int input)
{
    int i;
    printf("{");
    for(i=1;i<=k;i++)
        if(a[i])
            printf(" %d",i);
    printf(" }\n");
}

bool finished = 0; /* 是否获得全部解? */
void backtrack(int a[], int k, int input)
{
    int c[MAXCANDIDATES]; /*这次搜索的候选 */
    int ncandidates; /* 候选数目 */
    int i; /* counter */
    if (is_a_solution(a,k,input))
        process_solution(a,k,input);
    else {
        k = k+1;
        construct_candidates(a,k,input,c,&ncandidates);
        for (i=0; i<ncandidates; i++) {
            a[k] = c[i];
            //make_move(a,k,input);
            backtrack(a,k,input);
            //unmake_move(a,k,input);
            if (finished) return; /* 如果符合终止条件就提前退出 */
        }
    }
}

void generate_subsets(int n)
{
    int a[NMAX];
    backtrack(a,0,n);
}

int main(){
    int n;
    scanf("%d", &n);
    generate_subsets(n);

    return 0;
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//格雷码生成
/*涉及到位操作的都看不懂*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void process_solution(int a[],int k, int n);
int print_bin(int num);
int e2(int n);

void gray_code(int a[],int k, int n)
{
    int i,j;
    if(k==n+1)
        process_solution(a,k,n);
    else {
        for(i=e2(k)-1,j=e2(k);i>=0;i--,j++)
            a[j] = (1<<k)+a[i];
        gray_code(a,k+1,n);
    }
}

void process_solution(int a[],int k,int n)
{
    int i;
    int j = e2(n);
    for(i=0;i<j;i++) {
        print_bin(a[i]);
        printf("\n");
    }
    return;
}

int print_bin(int num)
{
    int pes_num=0;
    int i=1,bits=4;
    if(num==0)
        bits--;
    while(num>0) {
        if(num%2)
            pes_num += i;
        i *= 10;
        num /= 2;
        bits--;
    }
    for(;bits>0;bits--)
        printf("0");
    printf("%d",pes_num);
    return 0;
}

int e2(int n)
{
    int res = 1;
    assert(n<16 && n>= 0);
    while(n>0) {
        res *= 2;
        n--;
    }
    return res;
}

int generate_gray_code(int n)
{
    int *a;
    a = (int *)malloc(e2(n)*sizeof(int));   //be careful about here
    a[0] = 0;
    gray_code(a,0,4);
}

int main()
{
    generate_gray_code(4);
    //int i;
    //for(i=0;i<16;i++)
    //{
    //    print_bin(i);
    //    printf("\n");
    //}
}



//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


/*
 位运算求子集树
以前求子集树都是用回溯法，
今天在topcoder做SRM时学到一种求子集树的新方法：位运算。
第一重循环是枚举所有子集，共2^n个，即1 << n个
第二重循环求集合所有j个元素的值，0或1。
求一下1 & (1 << j)的值就可以知道它的原理。
*/

#include<iostream>
using namespace std;
const int n = 4;
int x[n];
//回溯法

/*回溯法与递归，我还是搞不懂，这到底是怎么回事*/
void backtrack(int t)
{
    if(t >= n)
    {
        for(int i = 0; i < n; i++)
            cout<<x[i];
        cout<<endl;
    }
    else
    {
        for(int i = 0; i <= 1; i++)
        {
            x[t] = i;
            backtrack(t + 1);
        }
    }
}
//位运算
/*能输出全部的子集吗？*/
void bitOperate()
{
    for(int i = 0; i < (1 << n); i++)
    {
        for(int j = 0; j < n; j++)
        {
            if( (i & (1 << j) ) == 0)
                x[j] = 0;
            else
                x[j] = 1;
        }
        for(int j = 0; j < n; j++)
            cout<<x[j];
        cout<<endl;
    }
}
int main()
{
    backtrack(0);
    cout<<endl;
    bitOperate();
    return 0;
}
