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
