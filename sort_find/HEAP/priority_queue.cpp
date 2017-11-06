//用堆实现优先队列

//转自：http://blog.csdn.net/acm_lkl/article/details/44184441

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

#define INF 0x3f3f3f3f

///一般的队列满足先进先出的性质，而优选队列不同，其
///总是最大的/最小的先出队。借助于堆的性质，我们可以
///在lgn的时间内实现优选队列的任何操作
void swp(int &a,int &b)
{
      int t=a;
      a=b;
      b=t;
}

void MaxHeadfly(int *a,int i,int HeadSize)///堆调整函数
{
        int largest;
        int l=i*2,r=2*i+1;
        if(a[i]<a[l]&&l<=HeadSize)
             largest=l;
        else
             largest=i;
        if(a[largest]<a[r])
             largest=r;
        if(largest!=i)
        {
             swp(a[i],a[largest]);
             MaxHeadfly(a,largest,HeadSize);
        }
}

void BuildMaxHead(int *a,int n) ///建立一个最大堆
{
        int k=n/2;
        for(int i=k;i>=1;i--)
               MaxHeadfly(a,i,n);
}

///以下为优先队列的操作

int MaxNum(int *a) ///取出最大的元素
{
      return a[1];   ///直接返回
}

void IncreaseKey(int *a,int x,int k)
{   ///将堆中编号为x的元素的值提升到k,k不能小于原来的值。
     ///这种提升只可能会导致父节点不满足最大堆的性质，所以直接向上递归的检查
     a[x]=k;
     while(x>1&&a[x/2]<a[x])
     {
             swp(a[x],a[x/2]);
             x=x/2;
     }
}

int ExtractMax(int *a,int &HeadSize)
{    ///去掉堆中最大的元素，并返回其值
      ///思想类似于堆排序的一次调整:我们先交换a[1]与a[HeadSize]的值
      ///然后再将HeadSize的值减1(相当于去掉一个叶子节点)；然后再调用
      ///MaxHeadfly(a,1,HeadSize)对堆进行调整，保证堆的性质。
      swp(a[1],a[HeadSize]);
      HeadSize--;
      MaxHeadfly(a,1,HeadSize);
      return a[HeadSize];
}

void Insert(int *a,int &HeadSize,int x)
{    ///向堆中加入一个元素x
     ///思想：先在堆中加入一个叶子节点，并将其值赋值为-INF
     ///然后再调用上面的调整函数将该叶子节点的值调整为x

     HeadSize++;  ///增加一个叶子节点
     a[HeadSize]=-1*INF;
     IncreaseKey(a,HeadSize,x);
}

int main()
{
        int a[10];
        int n=5;
        cout<<"请输入5个数: "<<endl;
        for(int i=1;i<=n;i++)
             cin>>a[i];
        int HeadSize=n;
        BuildMaxHead(a,n);
        ///取出队列中 最大的那个元素
        cout<<"最大的元素是: "<<MaxNum(a)<<endl;
        ExtractMax(a,HeadSize);
        cout<<"移除最大元素后，剩下元素中最大的是: "<<MaxNum(a)<<endl;
        ///将第4个元素增加到100
        IncreaseKey(a,4,100);
        cout<<"将第4个元素增加到100后,最大元素是: "<<MaxNum(a)<<endl;
        ///将110插入到队列中
        Insert(a,HeadSize,110);
        cout<<"插入110后，最大元素是: "<<MaxNum(a)<<endl;
   return 0;
}
