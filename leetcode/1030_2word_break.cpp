/*
时间限制：1秒 空间限制：32768K
本题知识点： 动态规划 leetcode

题目描述

Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
Return all such possible sentences.
For example, given
s ="catsanddog",
dict =["cat", "cats", "and", "sand", "dog"].
A solution is["cats and dog", "cat sand dog"].
*/

//运行时间：14ms 占用内存：528k

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int len = s.length();
        dp = new vector<bool>[len];
        for( int pos = 0; pos < len; pos++ ){
            for( int i = 1; i < len - pos + 1; i++ ){
                if( dict.find( s.substr(pos, i) ) != dict.end() )
                    dp[pos].push_back(true);
                else
                    dp[pos].push_back(false);
            }
        }
        dfs( s, len-1 );
        return res;
    }
    
    void dfs( string s, int n ){
        if( n >= 0 ){
            for( int i = n; i >= 0; i-- ){
                if( dp[i][n-i] ){
                    mid.push_back( s.substr( i, n-i+1 ) );
                    dfs( s, i-1 );
                    mid.pop_back();
                }
            }
        }
        else{
            string r;
            for( int j = mid.size() - 1; j >= 0; j-- ){
                r += mid[j];
                if( j >0 )
                    r += " ";
            }
            res.push_back(r);
        }
    }
    vector<bool> *dp;
    vector<string> res;
    vector<string> mid;
};

思路CSDN Allan:
=================================思路Allan========================================
s ="catsand",
dict =["cat", "cats", "and", "sand", "dog"].
 
动态规划根本思想是记录状态值:
DP[i][j]:
           j    0       1       2       3       4       5       6  
        i 
        0       c       ca      cat(1)  cats(1) catsa   catsan  catsand
        1               a       at      ats     atsa    atsan   atsand       
        2                       t       ts      tsa     tsan    tsand
        3                               s       sa      san     sand(1)
        4                                       a       an      and(1)
        5                                               n       nd
        6                                                       d
 
DP[i][j]里:
0       c       ca      cat(1)  cats(1) catsa   catsan  catsand
1       a       at      ats     atsa    atsan   atsand
2       t       ts      tsa     tsan    tsand
3       s       sa      san     sand(1)
4       a       an      and(1)
5       n       nd
6       d
思路:
DP[i][j]存放着字符串s的所有子字符串在dict中的状态值。
遍历顺序是先搜索i到串尾的子串，若子串在dict里，再搜索串头到i的子串。
        c a t s a n d
        j     i
比如，dp[3][3]=1表明"sand"在dict里，再搜索cat......
再搜索顺序为cat at t......
 
 
output(6,s):
i=6     k:0 1 2 3 4 5 6
dp[k][i-k]:偏移为k，截断字符串长度i-k+1
沿着次对角线遍历,相当于从头部每隔一个字符截断!!!
dp[0][6]:偏移为0，截断字符串长度7      0
dp[1][5]:偏移为1，截断字符串长度6      0
dp[2][4]:偏移为2，截断字符串长度5      0
dp[3][3]:偏移为3，截断字符串长度4      1   -->output(2,s)
dp[4][2]:偏移为4，截断字符串长度3      1   -->output(3,s)
dp[5][1]:偏移为5，截断字符串长度2      0
dp[6][0]:偏移为6，截断字符串长度1      0
 
output(2,s):
i=2     k:0 1 2
dp[k][i-k]:偏移为k，截断字符串长度i-k+1
沿着次对角线遍历,相当于从头部每隔一个字符截断!!!
dp[0][2]:偏移为0，截断字符串长度3      1   -->output(-1,s)
dp[1][1]:偏移为1，截断字符串长度2      0
dp[2][0]:偏移为2，截断字符串长度1      0
 
output(-1,s):
......
 
 
mystring.push_back(s.substr(k,i-k+1));
output(k-1,s);
s.substr(k,i-k+1)==>递归output(k-1,s)!!!
偏移为k,截断长度i-(k-1);                           ------
==>递归为k-1                                              |--->处理字符串长度i 
从偏移为0，截断长度k开始以次对角线方向遍历!!!       ------
================================================================================
 
*/
