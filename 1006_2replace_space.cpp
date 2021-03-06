/*
时间限制：1秒 空间限制：32768K
本题知识点： 字符串

题目描述
请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

*/

//运行时间：1ms，占用内存：504K

class Solution {
public:
    void replaceSpace( char *str, int length ){
        if( str == NULL || length <= 0 )
            return;
        int originalLength = 0;
        int numberOfBlank = 0;
        int i = 0;
        while( str[i] != '\0' ){
            ++ originalLength;
            
            if( str[i] == ' ' )
                ++ numberOfBlank;
            ++i;
        }
        
        int newLength = originalLength + numberOfBlank * 2;
        if(newLength > length)
            return;
        
        int indexOfOriginal = originalLength;
        int indexOfNew = newLength;
        while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal){
            if( str[indexOfOriginal] == ' ' ){
                str[indexOfNew --] = '0';
                str[indexOfNew --] = '2';
                str[indexOfNew --] = '%';
            }
            else{
                str[indexOfNew --] = str[indexOfOriginal];
            }
            --indexOfOriginal;
        }
    }
};
