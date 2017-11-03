//转自：http://blog.csdn.net/yeruby/article/details/38615045

//http://www.cnblogs.com/biyeymyhjob/archive/2012/07/30/2615542.html
//这里面虽然没有代码，但是思想原理讲的很清楚

#include<iostream>  
//#include<fstream>  
using  namespace std;  
  
#define MAX 100  
#define MAXCOST 0x7fffffff  
  
int graph[MAX][MAX];  
  
int prim(int graph[][MAX], int n)  
{  
    int lowcost[MAX];  
    int mst[MAX];  
    int i, j, min, minid, sum = 0;  
    for (i = 2; i <= n; i++)  
    {  
        lowcost[i] = graph[1][i];  
        mst[i] = 1;  
    }  
    mst[1] = 0;  
    for (i = 2; i <= n; i++)  
    {  
        min = MAXCOST;  
        minid = 0;  
        for (j = 2; j <= n; j++)  
        {  
            if (lowcost[j] < min && lowcost[j] != 0)  
            {  
                min = lowcost[j];  
                minid = j;  
            }  
        }  
        cout << "V" << mst[minid] << "-V" << minid << "=" << min << endl;  
        sum += min;  
        lowcost[minid] = 0;  
        for (j = 2; j <= n; j++)  
        {  
            if (graph[minid][j] < lowcost[j])  
            {  
                lowcost[j] = graph[minid][j];  
                mst[j] = minid;  
            }  
        }  
    }  
    return sum;  
}  
  
int main()  
{  
    int i, j, k, m, n;  
    int x, y, cost;  
    //ifstream in("input.txt");  
    cin >> m >> n;//m=顶点的个数，n=边的个数  
    //初始化图G  
    for (i = 1; i <= m; i++)  
    {  
        for (j = 1; j <= m; j++)  
        {  
            graph[i][j] = MAXCOST;  
        }  
    }  
    //构建图G  
    for (k = 1; k <= n; k++)  
    {  
        cin >> i >> j >> cost;  
        graph[i][j] = cost;  
        graph[j][i] = cost;  
    }  
    //求解最小生成树  
    cost = prim(graph, m);  
    //输出最小权值和  
    cout << "最小权值和=" << cost << endl;  
    system("pause");  
    return 0;  
}  

/*
input:
6 10  
1 2 6  
1 3 1  
1 4 5  
2 3 5  
2 5 3  
3 4 5  
3 5 6  
3 6 4  
4 6 2  
5 6 6  

Output：

V1-V3=1  
V3-V6=4  
V6-V4=2  
V3-V2=5  
V2-V5=3  
最小权值和=15  
请按任意键继续. . .  
*/
