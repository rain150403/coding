/*
//功能：删除字符串中重复出现的字符
//样例：google 输出：gole
//思路：哈希表过滤法。第1步，初始化一个哈希表，用以存储字符（key）及字符出现的次数；第2步，遍历哈希表，进行统计计数；第3步，输出统计次数为1及统计次数
多余1的（输出1次）。如果多于1次则只显示一次，时间复杂度：O（n）。这里考虑多定义加一个新数组来存放输出。
*/

//功能：删除字符串中重复出现的字符  
//样例：google 输出：gole  
  
#include <iostream>  
using namespace std;  
  
char DeleteRepeating(char *InputStr, char *pOutputStr)  
{  
    //输入不合法  
    if(InputStr == NULL)  
        return 0;  
  
    //创建一个哈希表  
    const int tableSize = 256;  
    unsigned int hashTable[tableSize];  
    int outcnt = 0;  
    for(int i = 0;i < tableSize; i++)  
        hashTable[i] = 0;  
  
    char *pHashKey = InputStr;  
    while(*pHashKey)  
    {  
        hashTable[*pHashKey]++;  
        pHashKey++;  
    }  
  
    pHashKey = InputStr;  
  
    //只对出现一次的一次储存，出现两次的也只储存一次  
    while(*pHashKey)  
    {  
        if(hashTable[*pHashKey] == 1)  
        {  
            pOutputStr[outcnt++] = *pHashKey;  
        }  
        else if(hashTable[*pHashKey] > 1)  
        {  
            pOutputStr[outcnt++] = *pHashKey;  
            hashTable[*pHashKey] = 0;  
        }  
        pHashKey++;  
    }  
        pOutputStr[outcnt++] = '\0';  
}  
  
int main()  
{  
    char str[100];  
    char str_out[100];  
    cout << "请输入字符： ";  
    cin >> str;  
  
  
    DeleteRepeating(str,str_out);  
    cout << str_out << endl;  
  
    return 0;  
}  
