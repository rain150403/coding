//一摞烙饼的排序

/*　　假设有一堆烙饼，大小不一，需要把它们摆成从下到上由大到小的顺序。每次翻转只能一次翻转最上面的几个烙饼，把它们上下颠倒。反复多次可以使烙饼有序。那么，最少应该翻转几次呢？

解答：

　　根据《编程之美》的分析可知，对于n个烙饼，如果每次都把最大的先翻到最上面，然后再把它翻到最下面，这样就只用处理最上面的(n-1)个。而翻完n-1个时，最小的必然已经在上面，因此，翻转的上界是2(n-1)。

　　为了在搜索解的时候剪枝，如果当前翻转次数多于上界2(n-1)，则必然不是最少的，应该直接返回。

　　同时，当烙饼内部几个部分分别有序时（比如3、4、5已经连在一起、9、10已经连在一起），不应该拆散它们，而是应该视为一个整体进行翻转。这样，每次把最大的和次大的翻在一起，肯定要优于上界。把这个不怎么紧密的下界记为LowerBound，值为顺序相邻两个烙饼大小不相邻顺序的对数(pairs，不是log)。

　　这样，有了粗略的上界和下界，就可以进行剪枝了。为了更有效的剪枝，可以把当前翻转步数大于已记录解的翻转步数的所有解也给剪掉。

　　套用回溯法的框架，以下是求解代码。虽然和《编程之美》上的C++的面向对象版本看上去不太一样，但实质是一样的：

    其实理解这个算法的关键是如何把“翻转烙饼”的过程抽象成数据结构的改变，回溯法倒不是那么重要。*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int* data;

int is_a_solution(int a[],int k, int step);
//void construct_candidates(int a[],int k,data input, int c[],int *ncandidates);
void process_solution(int a[],int n,int step, data input,data output);
//void make_move(int a[],int k, data input);
//void unmake_move(int a[],int k,data inupt);

int LowerBound(int *CakeArray,int n);
int UpperBound(int n);
void Reverse(int CakeArray[],int begin,int end);
void generate_sort(int a[],int n);
void show(data output);
static int maxStep;

//is_sorted()
int is_a_solution(int *CakeArray,int n,int step)
{
    int i;
    for(i=1;i<n;i++)
        if(CakeArray[i-1]>CakeArray[i])
            return 0;
    if(step<maxStep)
        return 1;
    return 0;
}

void process_solution(int a[],int n,int step,data input,data output)
{
    int i;
    maxStep = step;
    printf("new maxStep:%d\n",maxStep);
    for(i=0;i<step;i++)
        output[i] = input[i];
    return;
}

int UpperBound(int n)
{
    return 2*(n-1);
}

int LowerBound(int *CakeArray,int n)
{
    int i,t,ret = 0;
    for(i=1;i<n;i++)
    {
        t = CakeArray[i-1] - CakeArray[i];
        if((t==1)||(t==-1))
            continue;
        else
            ret++;
    }
    return ret;
}

void Reverse(int CakeArray[],int begin,int end) {
    assert(end>begin);
    int i,j,t;
    for(i=begin,j=end;i<j;i++,j--)
    {
        t = CakeArray[i];
        CakeArray[i] = CakeArray[j];
        CakeArray[j] = t;
    }
}

void backtrack(int a[],int n,int step, data input,data output)
{
    int i;
    if(step+LowerBound(a,n)>maxStep)
        return;
    if(is_a_solution(a,n,step))
        process_solution(a,n,step,input,output);
    else {
        //construct_candidates(a,k,input,c,&ncandidates);
        for(i=1;i<n;i++) {
            Reverse(a,0,i);//make_move(a,k,input);
            input[step] = i;
            backtrack(a,n,step+1,input,output);
            Reverse(a,0,i);//unmake_move(a,k,input);
        }
    }
}

void generate_sort(int a[],int n)
{
    maxStep = UpperBound(n);
    int *SwapArray;
    SwapArray = (int *)malloc((UpperBound(n)+1)*sizeof(int));
    int *minSwapArray;
    minSwapArray = (int *)malloc((UpperBound(n)+1)*sizeof(int));
    backtrack(a,n,0,SwapArray,minSwapArray);
    show(minSwapArray);
}

void show(data output)
{
    int i;
    for(i=0;i<maxStep;i++)
        printf("%d",output[i]);
    printf("\n");
    return ;
}


int main() {
    int i,n;
    printf("number of pancake:");
    scanf("%d",&n);
    int *CakeArray;
    CakeArray = (int *)malloc(n*sizeof(int));
    printf("pancakes' order(continuously):\n");
    for(i=0;i<n;i++)
        scanf("%d",&CakeArray[i]);
    printf("searching...\n");
    generate_sort(CakeArray,n);
    return 0;
}
