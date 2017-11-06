/*
全排列（ 有无重复数字 ）
1）字典序
2）STL
3）递归
*/

//转自：http://blog.csdn.net/laojiu_/article/details/51115352

//方法一、字典序（无重复）
#include<iostream>  
#include<algorithm>  
  
using namespace std;

#define MAX 100
int array[MAX] = {0}; 
  
void Permutation()  
{  
    int len;  
    
    scanf( "%d ", &len );
    for( int i = 0; i < len; i++ ){
        scanf( "%d ", &array[i] );
    }
    int j, k;  
  
    while (true)  
    {
        for( int i = 0; i < len; i++ ){
            printf( "%d ", array[i] );
        }
        printf( "\n" );
  
        for (j = len - 2; j >= 0 && arry[j] > arry[j + 1]; j--);//注意此处 j >= 0 判断条件在前  
  
        if (j < 0) return;//结束  
          
        for (k = len - 1; k > j&&arry[k] < arry[j]; k--);  
  
        swap(arry[k], arry[j]);  
  
        for (int l = j + 1, r = len - 1; l < r; l++, r--)  
            swap(arry[l], arry[r]);  
    }  
}  
  
int main()  
{  
  
    Permutation();  
  
    return 0;  
}  

//有重复（其实只在一个地方加了一个“=”）

#include<iostream>  
#include<algorithm>  
  
using namespace std;  
  
int arry[3] = { 1,2,2 };//len==3;  
  
void Permutation()  
{  
    int len = 3;  
    int j, k;  
  
    while (true)  
    {  
        printf("%d%d%d\n", arry[0], arry[1], arry[2]);  
  
        for (j = len - 2; j >= 0 && arry[j] >= arry[j + 1]; j--);//注意此处 j >= 0 判断条件在前,加个等号即可  
  
        if (j < 0) return;//结束  
  
        for (k = len - 1; k > j&&arry[k] <= arry[j]; k--);//加个等号即可  
  
        swap(arry[k], arry[j]);  
  
        for (int l = j + 1, r = len - 1; l < r; l++, r--)  
            swap(arry[l], arry[r]);  
    }  
}  
  
int main()  
{  
  
    Permutation();  
  
    return 0;  
}  

//关于字典序，我觉得这里说的简单清楚 http://www.cnblogs.com/darklights/p/5285598.html

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
STL---《algorithm》中的两个函数next_permutation和prev_permutation。
next_permutation:对于当前的排列，如果在字典序中还存在下一个排列，返回真，并且将下一个排列赋予当前排列，如果不存在，就把当前排列进行递增排序。
prev_permutation对于当前的排列，如果在字典序中还存在前一个排列，返回真，并且将前一个排列赋予当前排列，如果不存在，就把当前排列进行递减排序。
那么利用next_permutation可以很轻松的实现全排列。
*/

//方法二、STL（无重复数字）
#include<iostream>  
#include<algorithm>  
  
using namespace std;  

#define MAX 100
int arry[3] = { 1,2,3 };//len==3;  
  
void Permutation()  
{  
    do  
        printf("%d%d%d\n", arry[0], arry[1], arry[2]);  
    while (next_permutation(arry, arry + 3));  
      
}  
  
int main()  
{  
  
    Permutation();  
  
    return 0;  
}  
