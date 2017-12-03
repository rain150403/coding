/*
题目：在英语中，如果两个单词中出现的字母相同，并且每个字母出现的次数也相同，那么这两个单词互为变位词。请完成一个函数，判断输入的两个字符串是不是互为
变位词。
*/

#include <stdio.h>  
#include <string.h>  
  
bool is_anagram(char *a, char *b)  
{  
    if(a==NULL || b==NULL)  
        return false;  
    if(strlen(a)!=strlen(b))//如果长度不等，则不为变位词  
        return false;  
    char hash_table[256] = {0};//创建简单哈希数组，下标为字符的ASCII码，数组值是字符出现的次数  
    char *p = a;  
    while(*p != '\0')  
        hash_table[*p++]++;  
    p = b;  
    while(*p != '\0')  
        hash_table[*p++]--;  
    int i;  
    for(i=0;i<256;i++)  
    {  
        if(hash_table[i]!=0)//如果数组值不为0，代表两个字符串中出现的字符不完全一致，不是变位词  
            return false;  
    }  
    return true;  
}  
  
int main()  
{  
    char a[] = "silent";  
    char b[] = "listen";  
    bool flag = is_anagram(a,b);  
    if(flag)  
        printf("%s和%s是变位词\n",a,b);  
    else  
        printf("%s和%s不是变位词\n",a,b);  
    return 0;  
}  
