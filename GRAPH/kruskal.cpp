//转自：http://blog.csdn.net/zenail501129/article/details/23551909

#include<stdio.h>  
#include<stdlib.h>  
#include<iostream>  
using namespace std;  
  
#define MAXN 11     //顶点个数的最大值  
#define MAXM 20     //边的个数的最大值  
struct edge         //边  
{  
    int u, v, w;  
}edges[MAXM];       //边的数组  
int parent[MAXN];   //parent[i]为顶点i所在集合对应的树中的根结点  
int n, m;           //顶点个数、边的个数  
int i, j;           //循环变量  
void UFset()        //初始化   
{  
    for(i = 1; i <= n; i++) parent[i] = -1;  
}  
int Find(int x)     //查找并返回结点x所属集合的根结点  
{  
    int s;          //查找位置  
    for(s = x; parent[s] >=0; s = parent[s]) ;  
    while(s != x)   //优化方案——压缩路径，使后续的查找操作加速  
    {  
        int tmp = parent[x];  
        parent[x] = s;  
        x = tmp;  
    }  
    return s;  
}  
//运用并查集，将两个不同集合的元素进行合并，使两个集合中任意两个元素都连通  
void Union(int R1, int R2)  
{  
    int r1 = Find(R1), r2 = Find(R2);       //r1和r2分别为R1和R2的根结点  
    int tmp = parent[r1] + parent[r2];      //两个集合结点数之和（负数）  
    //如果R2所在树结点个数 > R1所在树结点个数（注意parent[r1]是负数）  
    if(parent[r1] > parent[r2])  
    {  
        parent[r1] = r2;  
        parent[r2] = tmp;  
    }  
    else  
    {  
        parent[r2] = r1;  
        parent[r1] = tmp;  
    }  
}  
int cmp(const void *a, const void *b)       //实现从小到大的比较函数  
{  
    edge aa = *(const edge *)a, bb = *(const edge *)b;  
    return aa.w-bb.w;  
}  
void Kruskal()  
{  
    int sumweight = 0;      //生成树的权值  
    int num = 0;            //已选用的边的数目  
    UFset();                //初始化parent数组  
    for(i = 0; i < m; i++)  
    {  
        if(Find(edges[i].u) != Find(edges[i].v))  
        {  
            printf("%d %d %d\n", edges[i].u, edges[i].v, edges[i].w);  
            sumweight += edges[i].w; num++;  
            Union(edges[i].u, edges[i].v);  
        }  
        if(num >= n-1) break;  
    }  
    printf("The weight of MST is : %d\n", sumweight);  
}  
void main()  
{  
    scanf("%d%d", &n, &m);  //读入顶点个数和边数  
    for(int i = 0; i < m; i++)  
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w); //读入边的起点和终点  
    printf("The edges chosen are :\n");  
    qsort(edges, m, sizeof(edges[0]), cmp); //对边按权值从小到大排序  
    Kruskal();  
}  

/*
input:
7 9
1 2 28
1 6 10
2 3 16
2 7 14
3 4 12
4 5 22
4 7 18
5 6 25
5 7 24

//关于图的这一节，不理解题意，连输入为什么得不到结果都不知道
*/
