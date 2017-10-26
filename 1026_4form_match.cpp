/*
时间限制：1秒 空间限制：32768K
本题知识点： 字符串

题目描述
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指
字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
*/

/*
/*
思路：只有当模式串和字符串同时等于\0，才可以认为两个串匹配。
在匹配中，对于每个位的匹配可以分为三种情况
1、（相应位匹配||模式串为.&&字符串不是\0）&&模式串下一位是*
2、（相应位匹配||模式串为.&&字符串不是\0）&&模式串下一位不是*
3、相应位不匹配&&（模式位不为.||字符串是\0）
对应1，最复杂。分为*取0，*取1，*>=2三种情况。
*取0对应跳过当前匹配位，继续寻找patter的下一个匹配位，str不变，pattern+2
*取1对应当前匹配位算一次成功匹配，str+1，pattern+2
*取>=2对应一次成功匹配，继续匹配字符串的下一位是否匹配，str+1，pattern不变
三者取或。即只要有一种情况能匹配成功认为字符串就是匹配成功的。
对应2，相当于一次成功匹配，str+1，pattern+1
对应3，匹配失败，直接返回false
*/
*/

//运行时间：1ms 占用内存：500k

class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if( str == NULL || pattern == NULL )
            return false;
        return matchCore( str, pattern );
    }
    
    bool matchCore( char* str, char* pattern ){
        if( *str == '\0' && *pattern == '\0' )
            return true;
        if( *str != '\0' && *pattern == '\0' )
            return false;
        if( *(pattern + 1) == '*' ){
            if( *pattern == *str || ( *pattern == '.' && *str != '\0' ) )
                /*
                matchCore( str, pattern + 2 ) :模式串未匹配
                matchCore( str+1, pattern ):模式串已经成功匹配，尝试匹配下一个字符串
                matchCore( str+1, pattern + 2 ):模式串已经成功匹配，并且不匹配下一个字符串内容，
                注意这里 macthCore( str+1, pattern + 2 )重复考虑了（代码中已经去除）
                */
                return matchCore( str+1, pattern ) || matchCore( str, pattern + 2 );
            else
                return matchCore( str, pattern + 2 );
        }
        if( *str == *pattern || ( *pattern == '.' && *str != '\0' ) )
            return matchCore( str + 1, pattern + 1 );
        return false;
    }
};

class Solution {
public:
    bool match(char* str, char* pattern){
        if (pattern[0] == 0 && str[0] == 0){
            return true;
        }
   
        if (pattern[0] != 0 && pattern[1] == '*'){
            if (match(str, pattern + 2))
                return true;
        }
   
        if ((pattern[0] == '.' && str[0]) || str[0] == pattern[0]){
            if (match(str + 1, pattern + 1))
                return true;
            if (pattern[1] == '*' && match(str + 1, pattern)){
                return true;
            }
        }
   
        return false;   
    }
};
