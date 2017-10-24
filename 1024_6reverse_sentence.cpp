/*
时间限制：1秒 空间限制：32768K 
本题知识点： 字符串

题目描述
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的
意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不
在行，你能帮助他么？
*/

//运行时间：2ms 占用内存：496k

class Solution {
public:
    string ReverseSentence(string str) {
        int size = str.size();
        if( size == 0 )
            return "";
        int mark = 0;
        str += ' ';
        for( int i = 0; i < size+1; ++i ){
            if( str[i] == ' ' ){
                ReverseWord( str, mark, i-1 );
                mark = i+1;
            }
        }
        
        str = str.substr(0, size);
        ReverseWord( str, 0, size - 1 );
        return str;
    }
    void ReverseWord( string &str, int l, int r ){
        while( l < r ){
            swap( str[l], str[r] );
            ++l;
            --r;
        }
    }
};
