/*
题目：输入一个int型整数， 按照从右向左的阅读顺序， 返回一个不含重复数字的新的整数。

例如：
输入：9876673
输出：37689

*/

#include<iostream>  
using namespace std;  
  
int main()  
{  
    int num, result = 0;  
    cin >> num;  
    int a[10] = { 0 };  
    while (num != 0)  
    {  
        if (a[num % 10] == 0)  // 说明第一次出现  
        {  
            a[num % 10] = 1;  
            result = result * 10 + num % 10;  
        }  
        num = num / 10;  
    }  
    cout << result;  
}  

/*
说明：这样编程比较巧妙，如果第一次出现，就记录一下标志。只有当第一次出现时，才把它加到 result 里面。
如果把题目改一下的话：把重复出现的数字全部删除掉，那么程序可以这样修改。
*/
int main()  
{  
    int num,num_temp,result = 0;  
    cin >> num;  
    num_temp = num;  
    int a[10] = {0};  
    while (num != 0)  
    {  
        a[num % 10]++;  //记录一下出现多少次  
        num = num / 10;  
    }  
    while (num_temp != 0)  
    {  
        if (a[num_temp % 10] == 1)  //出现一次就加上去，  
        {  
            result = result * 10 + num_temp % 10;  // 当然了，可以不用累加。可以每次只输出一个数字。  
            num_temp = num_temp / 10;  
        }  
        else  
        {  
            num_temp = num_temp / 10;    // 出现一次以上直接忽略  
        }  
    }  
    cout << result;  
    return 0;  
}  
