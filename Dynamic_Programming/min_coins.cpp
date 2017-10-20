/*
给予不同面值的硬币若干种种（每种硬币个数无限多），用若干种硬币组合为某种面额的钱，使硬币的的个数最少。
*/

//用动态规划，而不是贪心算法

#include<iostream>  
using namespace std;  
//money需要找零的钱  
//coin可用的硬币  
//硬币种类  
void FindMin(int money,int *coin, int n)  
{  
    int *coinNum=new int[money+1]();//存储1...money找零最少需要的硬币的个数  
    int *coinValue=new int[money+1]();//最后加入的硬币，方便后面输出是哪几个硬币  
    coinNum[0]=0;  
  
    for(int i=1;i<=money;i++)  
    {  
        int minNum=i;//i面值钱，需要最少硬币个数  
        int usedMoney=0;//这次找零，在原来的基础上需要的硬币  
        for(int j=0;j<n;j++)  
        {  
            if(i>=coin[j])//找零的钱大于这个硬币的面值  
            {  
                //if(coinNum[i-coin[j]]+1<=minNum)//所需硬币个数减少了  
                /* 
                上面的判断语句有问题，在更新时，需要判断i-coin[j]是否能找的开，如果找不开，就不需要更新。 
                多谢zywscq 指正 
                */  
                if(coinNum[i-coin[j]]+1<=minNum&&(i==coin[j]||coinValue[i-coin[j]]!=0))//所需硬币个数减少了  
                {  
                    minNum=coinNum[i-coin[j]]+1;//更新  
                    usedMoney=coin[j];//更新  
                }  
            }  
        }  
        coinNum[i]=minNum;  
        coinValue[i]=usedMoney;  
    }  
  
    //输出结果  
    if(coinValue[money]==0)  
        cout<<"找不开零钱"<<endl;  
    else  
    {  
        cout<<"需要最少硬币个数为："<<coinNum[money]<<endl;  
        cout<<"硬币分别为:";  
        while(money>0)  
        {  
            cout<<coinValue[money]<<",";  
            money-=coinValue[money];  
        }  
    }  
    delete []coinNum;  
    delete []coinValue;  
}  
int main()  
{  
    int Money=18;  
    int coin[]={1,2,5,9,10};  
    FindMin(Money,coin,5);  
  
}  
