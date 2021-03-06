/*
定义一个实现任意两个整数的加法函数。
*/

#include<iostream>  
using namespace std;  
char *BigNunAdd(char *str1, char *str2)  
{  
    int len1 = strlen(str1);  
    int len2 = strlen(str2);  
    int len = len1 > len2?len1 : len2;  
    char *res = new char[len + 2];  
    memset(res, '0', len + 2);  
    res[len + 1] = '\0';  
  
    int p1 = len1 - 1;  
    int p2 = len2 - 1;  
    int p = len;  
    int ntake = 0;  
    //===  
    while (p1 >= 0 && p2 >= 0)  
    {  
        int temp =str1[p1] - '0' + str2[p2] - '0'+ntake;  
        ntake = 0;  
        if (temp >= 10)  
        {  
            ntake = 1;  
            temp -= 10;  
        }  
        res[p] += temp;  
        p--;  
        p1--;  
        p2--;  
    }  
    //===  
    if (p1 >= 0)  
    {  
        while (p1 >= 0)  
        {  
            int temp = str1[p1] - '0' + ntake;  
            ntake = 0;  
            if (temp >= 10)  
            {  
                ntake = 1;  
                temp -= 10;  
            }  
            res[p] += temp;  
            p--;  
            p1--;  
        }  
    }  
    //===  
    if (p2 >= 0)  
    {  
        while (p2 >= 0)  
        {  
            int temp = str1[p2] - '0' + ntake;  
            ntake = 0;  
            if (temp >= 10)  
            {  
                ntake = 1;  
                temp -= 10;  
            }  
            res[p] += temp;  
            p--;  
            p2--;  
        }  
    }  
    res[p] += ntake;  
    //===  
    return res;  
}  
void main()  
{  
    char *str1 = "236488";  
    char *str2 = "901124";  
    char *res = BigNunAdd(str1, str2);  
    if (res[0] != '0')  
    {  
        cout << str1 << "+" << str2 << "=:" << res << endl;  
    }  
    else  
    {  
        char *_res = res;  
        _res++;  
        cout << str1 << "+" << str2 << "=:" << _res << endl;  
    }  
    delete[]res;  
}  
