//求一个n元集合的k元子集（n>=k>0）

//如果想采用"求一个集合的所有子集"的解法，需要稍作修改，使得遍历至叶结点（也即所有元素都进行标记是否在集合中）时，判断是不是一个解，即元素数目是否为k。满足才能输出。

#include <stdio.h>
#define MAXCANDIDATES 100000
#define NMAX 100000
typedef int data;

int is_a_solution(int a[],int k, data input);
void construct_candidates(int a[],int k,data input, int c[],int *ncandidates);
void process_solution(int a[],int k, data input);

static int finished = 0;

void construct_candidates(int a[],int k, data input, int c[],int *ncandidates)
{
    c[0] = 1;
    c[1] = 0;
    *ncandidates = 2;
}

void process_solution(int a[],int k,data input)
{
    int i;
    printf("{");
    for(i=1;i<=k;i++)
        if(a[i])
            printf(" %d",i);
    printf(" }\n");
}

void backtrack(int a[],int k, data input,int n,int num)
{
    int c[MAXCANDIDATES];
    int ncandidates;
    int i;
    if(n == num) {//is a solution
        process_solution(a,k,input);
        return;
    }
    else if ((num>n)||(k==input))//not a solution
        return;
    else{
        k=k+1;
        construct_candidates(a,k,input,c,&ncandidates);
        for(i=0;i<ncandidates;i++) {
            a[k] = c[i];
            if(c[i]) {
                num++;
                backtrack(a,k,input,n,num);
                num--;
            }
            else
                backtrack(a,k,input,n,num);

            if (finished)
                return;
        }
    }
}

void generate_subsets(int n, int m )
{
    int a[NMAX+1];
    backtrack(a,0,n,m,0);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m );
    generate_subsets(n, m);

    return 0;
}
