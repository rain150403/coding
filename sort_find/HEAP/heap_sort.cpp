/*
建堆的两种方式：
1.不知道一共有多少个元素，那就来一个我插入一个，插入之后，要和父节点比较，调整，如此反复，直到插入所有元素。
2.一开始就知道一共有多少个元素，直接摆成完全二叉树的样子，扫描一半的元素（n/2-1 ~  0 只有这些节点有子节点），从下到上，从右到左与自己的
子节点比较，并调整最终形成最大堆。

（完全二叉树可单，满二叉树必须满，当然它们都可以不完满）

一、maxHeapInsert方法
     maxHeapInsert方法和前面的办法不一样。它可以假定我们事先不知道有多少个元素，通过不断往堆里面插入元素进行调整来构建堆。

它的大致步骤如下：

1. 首先增加堆的长度，在最末尾的地方加入最新插入的元素。

2. 比较当前元素和它的父结点值，如果比父结点值大，则交换两个元素，否则返回。

3. 重复步骤2.

二、buildMaxHeap方法
     buildMaxHeap方法的流程简单概括起来就是一句话，从A.length / 2一直到根结点进行maxHeapify调整。
     
转自：https://www.cnblogs.com/shytong/p/5364470.html
*/




//堆排序
//转自：http://blog.csdn.net/acm_lkl/article/details/44184441

#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define MAX 1000

int swp(int &a,int &b)
{
       int t=a;
        a=b;
        b=t;
}

void MaxHeadfly(int *a,int i,int HeadSize)
{  
        int l=2*i,r=2*i+1; ///取出节点i的左右儿子节点的编号
        int largest;  ///记录最大值的节点编号
        if(a[i]<a[l]&&l<=HeadSize)
            largest=l;
        else
            largest=i;
       if(a[largest]<a[r]&&r<=HeadSize)
            largest=r;
        if(largest!=i)
        {///递归调整受影响的子树
                swp(a[i],a[largest]);
                MaxHeadfly(a,largest,HeadSize);
        }
}

void BuildMaxHead(int *a,int n)
{ 
  for(int i=n/2;i>=1;i--)
          MaxHeadfly(a,i,n);
}

void HeadSort(int *a,int n)
{
        BuildMaxHead(a,n);  ///建立一个大根堆
        int HeadSize = n;
        for(int i=n;i>=2;i--) ///堆的规模不断减少
        {
               swp(a[1],a[i]);
               HeadSize--;   ///交换以后就要减少堆的大小
               MaxHeadfly(a,1,HeadSize);   ///根节点改变了,重新调整成大根堆
        }
}

int main()
{
      int n,a[MAX];
      scanf( "%d", &n );
      cout<<"请输入"<<n<<"个数："<<endl;
      for(int i=1;i<=n;i++)
           cin>>a[i];
      HeadSort(a,n);
      cout<<"排序以后的数组："<<endl;
      for(int i=1;i<=n;i++)
          cout<<a[i]<<" ";
      cout<<endl;
   return 0;
}
