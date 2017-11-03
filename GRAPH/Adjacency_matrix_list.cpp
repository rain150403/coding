//转自：http://blog.csdn.net/luoshixian099/article/details/51888031

// list

#include <iostream>
using namespace std;
typedef struct VertexNode  //链表表头结点
{
    char data;
    struct ArcNode * firstarc;//指向第一条边
}VertexNode;
typedef struct ArcNode  //边链表结点
{
    char data;
    struct ArcNode * nextarc;//指向下一条边
}ArcNode;
ArcNode * InSertArcNode(char name) //新建边结点，待插入到边链表中
{
    ArcNode * p = new ArcNode;
    p->data = name;
    p->nextarc = NULL;
    return p;
}
VertexNode * AdjList()//邻接链表表示法
{
    ArcNode * p=NULL;
    VertexNode * List_head = new VertexNode[9]; //顺序存储表头结点
    int count = 0;
    List_head[count].data = 'A';
    p = List_head[count].firstarc = InSertArcNode('B');
    p = p->nextarc = InSertArcNode('D');
    p = p->nextarc = InSertArcNode('E');
    count++;
    List_head[count].data = 'B';
    p = List_head[count].firstarc = InSertArcNode('A');
    p = p->nextarc = InSertArcNode('C');
    p = p->nextarc = InSertArcNode('E');
    count++;
    List_head[count].data = 'C';
    p = List_head[count].firstarc = InSertArcNode('B');
    p = p->nextarc = InSertArcNode('F');
    count++;
    List_head[count].data = 'D';
    p = List_head[count].firstarc = InSertArcNode('A');
    p = p->nextarc = InSertArcNode('G');
    count++;
    List_head[count].data = 'E';
    p = List_head[count].firstarc = InSertArcNode('A');
    p = p->nextarc = InSertArcNode('B');
    p = p->nextarc = InSertArcNode('G');
    count++;
    List_head[count].data = 'F';
    p = List_head[count].firstarc = InSertArcNode('C');
    count++;
    List_head[count].data = 'G';
    p = List_head[count].firstarc = InSertArcNode('D');
    p = p->nextarc = InSertArcNode('E');
    p = p->nextarc = InSertArcNode('H');
    count++;
    List_head[count].data = 'H';
    p = List_head[count].firstarc = InSertArcNode('G');
    p = p->nextarc = InSertArcNode('I');
    count++;
    List_head[count].data = 'I';
    p = List_head[count].firstarc = InSertArcNode('H');

    return List_head;
}

int main()
{   
    char vextex[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };
    VertexNode * GRAPH = AdjList();  //创建图--邻接链表
    ArcNode *p = NULL;
    for (int i = 0; i < 9;i++)  //输出
    {
        cout << GRAPH[i].data << ": ";
        p = GRAPH[i].firstarc;
        while (p != NULL)
        {
            cout << p->data << ",";
            p = p->nextarc;
        }
        cout << endl;
    }
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

//matrix

#include <iostream>
using namespace std;
void AdjMatrix(char arc[][9])
{
    for (int i = 0; i < 9; i++)   //初始化邻接矩阵
        for (int j = 0; j < 9; j++)
        {
            arc[i][j] = 0;
        }
    arc[0][1] = arc[0][3] = arc[0][4] = 1;
    arc[1][0] = arc[1][2] = arc[1][4] = 1;
    arc[2][1] = arc[2][5] = 1;
    arc[3][0] = arc[3][6] = 1;
    arc[4][0] = arc[4][1] = arc[4][6] = 1;
    arc[5][2] = 1;
    arc[6][3] = arc[6][4] = arc[6][7] = 1;
    arc[7][6] = arc[7][8] = 1;
    arc[8][7] = 1;
}
int main()
{   
    char vextex[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };
    char arc[9][9] = { 0 };
    AdjMatrix(arc);
    for (int i = 0; i < 9; i++)
    {
        cout << vextex[i] << ": ";
        for (int j = 0; j < 9; j++)
        {
            if (arc[i][j]==1)
            {
                cout << vextex[j] << ",";
            }
        }
        cout << endl;
    }
    return 0;
}
