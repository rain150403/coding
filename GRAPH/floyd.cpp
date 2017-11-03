//各对顶点之间的最短距离。解决任意两点间的最短路径的一种算法，可以正确处理有向图或负权的最短路径问题，同时也被用于计算有向图的传递闭包。
注意区别于dijkstra算法。

//http://www.cnblogs.com/biyeymyhjob/archive/2012/07/31/2615833.html这里面虽然没有详细的代码，但是理论思想讲的很清楚。

/*每对顶点之间最短路径Floyd 2011.8.27*/ 

#include <iostream>
#include <stack>
#define M 100
#define N 100
usingnamespace std;

typedef struct node
{
    int matrix[N][M];      //邻接矩阵 
int n;                 //顶点数 
int e;                 //边数 
}MGraph; 

void FloydPath(MGraph g,int dist[N][M],int path[N][M])
{
    int i,j,k;
    for(i=0;i<g.n;i++)
        for(j=0;j<g.n;j++)
        {
            if(g.matrix[i][j]>0)
            {
                dist[i][j]=g.matrix[i][j];
                path[i][j]=i; 
            }
            else
            {
                if(i!=j)
                {
                    dist[i][j]=INT_MAX;
                    path[i][j]=-1;
                }
                else
                {
                    dist[i][j]=0;
                    path[i][j]=i;    
                }    
            }
        }
    for(k=0;k<g.n;k++)     //中间插入点(注意理解k为什么只能在最外层) 
for(i=0;i<g.n;i++)  
            for(j=0;j<g.n;j++)
            {
                if((dist[i][k]>0&&dist[i][k]<INT_MAX)&&//防止加法溢出 
                      (dist[k][j]>0&&dist[k][j]<INT_MAX)&&
                    dist[i][k]+dist[k][j]<dist[i][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    path[i][j]=path[k][j];   //path[i][j]记录从i到j的最短路径上j的前一个顶点 
                   }
            }    
}

void showPath(int path[N][M],int s,int t)    //打印出最短路径 
{
    stack<int> st;
    int v=t;
    while(t!=s)
    {
        st.push(t);
        t=path[s][t];
    }
    st.push(t);
    while(!st.empty())
    {
        cout<<st.top()<<"";
        st.pop();
    }
    
}

int main(int argc, char*argv[])
{
    int e,n;
    while(cin>>e>>n&&e!=0)
    {
        int i,j;
        int s,t,w;
        MGraph g;
        int dist[N][M],path[N][M];
        g.n=n;
        g.e=e;
        for(i=0;i<g.n;i++)
            for(j=0;j<g.n;j++)
                g.matrix[i][j]=0;
        for(i=0;i<e;i++)
        {
            cin>>s>>t>>w;
            g.matrix[s][t]=w;
        }
        FloydPath(g,dist,path);
        for(i=0;i<g.n;i++)
            for(j=0;j<g.n;j++)
                {
                    if(dist[i][j]>0&&dist[i][j]<INT_MAX)
                    {
                        showPath(path,i,j);
                        cout<<dist[i][j]<<endl;
                    }
                }                
    }
    return0;
}
