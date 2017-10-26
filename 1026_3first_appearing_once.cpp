/*
时间限制：1秒 空间限制：32768K
本题知识点： 字符串

题目描述
请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字
符“google"时，第一个只出现一次的字符是"l"。
输出描述:
如果当前字符流没有存在出现一次的字符，返回#字符。
*/

//运行时间：2ms 占用内存：512k

class Solution{
public:
    //Insert one char from stringstream
    void Insert(char ch){
        ++hashArray[ch-'\0'];
        if( hashArray[ch-'\0'] == 1){
            data.push_back(ch);
        }
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce(){
        while( !data.empty() && hashArray[data.front()] >= 2 ){
            data.pop_front();
        }
        if( data.empty() )
            return '#';
        return data.front();
    }
private:
    unsigned char hashArray[128];
    deque<char> data;
};

/*
思路：时间复杂度O（1），空间复杂度O（n）
        1、用一个128大小的数组统计每个字符出现的次数
        2、用一个队列，如果第一次遇到ch字符，则插入队列；其他情况不在插入
        3、求解第一个出现的字符，判断队首元素是否只出现一次，如果是直接返回，否则删除继续第3步骤

分析：可以看出相同的字符只被插入一次，最多push128个，同时大多数情况会直接返回队首。所以大家不要被里面的while循环迷惑
*/

class Solution{
public:
    //Insert one char from stringstream
    void Insert(char ch){  
        ++cnt[ch - '\0'];
        if(cnt[ch - '\0'] == 1)
           data.push(ch);
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce(){
        while(!data.empty() && cnt[data.front()] >= 2)
            data.pop();
        if(data.empty())
            return '#';
        return data.front();
    }
    Solution(){
        memset(cnt, 0, sizeof(cnt));
    }
private:
    queue<char> data;
    unsigned cnt[128];
};
