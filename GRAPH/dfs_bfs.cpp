#include<iostream>
#include<queue>
#include<stack>
#include<stdlib.h>
#define MAX 100
using namespace std;

typedef struct 
{
    int edges[MAX][MAX];    //邻接矩阵   adjacency matrix
    int n;                  //顶点数   number of vertices
    int e;                  //边数   number of edges
}MGraph;

bool visited[MAX];          //标记顶点是否被访问过   mark whether the vertices have been visited

void creatMGraph(MGraph &G)    //用引用作参数
{
    int i,j;
    int s,t;                 //存储顶点编号   storage vertex number
    int v;                   //存储边的权值   storage the weight of edges
    for(i=0;i<G.n;i++)       //初始化   initialize
    {
        for(j=0;j<G.n;j++)
        {
            G.edges[i][j]=0;
        }
        visited[i]=false;
    }
    for(i=0;i<G.e;i++)      //对矩阵相邻的边赋权值   the adjacent edge's weight
    {
        scanf("%d %d %d",&s,&t,&v);   //输入边的顶点编号以及权值   enter the vertex number and weight of the edge
        G.edges[s][t]=v;
    }
}

void DFS(MGraph G,int v)      //深度优先搜索
{
    int i;
    printf("%d ",v);          //访问结点v   visited node v
    visited[v]=true;
    for(i=0;i<G.n;i++)       //访问与v相邻的未被访问过的结点    visit nodes adjacent to v but not accessed
    {
        if(G.edges[v][i]!=0&&visited[i]==false)
        {
            DFS(G,i);
        }
    }
}

void DFS1(MGraph G,int v)   //非递归实现    none recursive implementation
{
    stack<int> s;
    printf("%d ",v);        //访问初始结点   visit initialization node
    visited[v]=true;
    s.push(v);              //入栈   into the stack
    while(!s.empty())
    {
        int i,j;
        i=s.top();          //取栈顶顶点   take the top of the stack
        for(j=0;j<G.n;j++)  //访问与顶点i相邻的顶点  visit vertices adjacent to vertex i
        {
            if(G.edges[i][j]!=0&&visited[j]==false)
            {
                printf("%d ",j);     //访问  visit
                visited[j]=true;
                s.push(j);           //访问完后入栈  put into the stack after visited
                break;               //找到一个相邻未访问的顶点，访问之后则跳出循环    find an adjacent unvisited vertex and then jump out of the loop
            }
        }
        if(j==G.n)                   //如果与i相邻的顶点都被访问过，则将顶点i出栈  if the vertices adjacent to i are all visited , the vertex i is out of the stack
            s.pop();
    }
}

void BFS(MGraph G,int v)      //广度优先搜索
{
    queue<int> Q;             //STL模板中的queue
    printf("%d ",v);
    visited[v]=true;
    Q.push(v);
    while(!Q.empty()) 
    {
        int i,j;
        i=Q.front();         //取队首顶点
        Q.pop();
        for(j=0;j<G.n;j++)   //广度遍历
        {
            if(G.edges[i][j]!=0&&visited[j]==false)
            {
                printf("%d ",j);
                visited[j]=true;
                Q.push(j);
            }
        }
    }
}

int main(void)
{
    int n,e;    //建立的图的顶点数和边数   the number of vertices and edges of the graph to be established 
    while(scanf("%d %d",&n,&e)==2&&n>0)
    {
        MGraph G;
        G.n=n;
        G.e=e;
        creatMGraph(G);
        DFS(G,0);
        printf("\n");
    //    DFS1(G,0);
    //    printf("\n");
    //    BFS(G,0);
    //    printf("\n");
    }
    return 0;
}

/*
输入：
5 4 （顶点个数，边的个数）
0 1 1
0 2 1
1 3 1
1 4 1（ 边的端点编号，以及权值）
*/
