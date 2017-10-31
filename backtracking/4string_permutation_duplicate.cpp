//给定一个字符串，生成组成这个字符串的字母的全排列
/*
如果字符串内字母不重复，显然和问题2一样。

　　如果字符串中有重复的字母，就比较麻烦了。不过套用回溯法框架仍然可以解决，为了简化候选元素的生成，将所有候选元素排列成数组，形成“元素-值”对，其中值代表这个元素还能出现几次，把ASCII码的A~Z、a~z映射为数组下标0~51。实现如下：
*/

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

#define NMAX 100000
#define MAXCANDIDATES 100000

int is_a_solution(char a[],int k, int len) {
    return (k==len);
}

void process_solution(char a[],int k, int len) {
    int i;
    for(i=1;i<=k;i++)
        printf("%c",a[i]);
    printf("\n");
}

bool finished = 0;
void backtrack(char a[],int k, int len,int candidate[])
{
    int i;
    if(is_a_solution(a,k,len))
        process_solution(a,k,len);
    else {
        k = k+1;
        for(i=0;i<MAXCANDIDATES;i++) {
            if(candidate[i]) {
                a[k] = i+ 'A' ;
                candidate[i] --;//make_move
                backtrack(a,k,len,candidate);
                candidate[i]++;//unmake_move
                if (finished)
                    return;
            }
        }
    }
}

void generate_permutations_of_string(char *p)
{
    //sort
    char a[NMAX];
    int candidate[MAXCANDIDATES];
    int i,len=strlen(p);
    for(i=0;i<MAXCANDIDATES;i++)
        candidate[i] = 0;
    for(i=0;i<len;i++)
        candidate[p[i] - 'A']++;
    backtrack(a,0,len,candidate);
}

int main(){
    char p[NMAX];
    gets(p);
    generate_permutations_of_string(p);

    return 0;
}
