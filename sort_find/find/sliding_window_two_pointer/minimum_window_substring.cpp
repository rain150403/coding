//所谓的使用哈希表就是使用map，set这些，而其实也可以用int数组实现？？？


/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

 

这道题的要求是要在O(n)的时间度里实现找到这个最小窗口字串，那么暴力搜索Brute Force肯定是不能用的，我们可以考虑哈希表，其中key是T中的字符，value是该字符
出现的次数。

- 我们最开始先扫描一遍T，把对应的字符及其出现的次数存到哈希表中。

- 然后开始遍历S，遇到T中的字符，就把对应的哈希表中的value减一，直到包含了T中的所有的字符，纪录一个字串并更新最小字串值。

- 将子窗口的左边界向右移，略掉不在T中的字符，如果某个在T中的字符出现的次数大于哈希表中的value，则也可以跳过该字符。

*/

class Solution {
public:
    string minWindow(string S, string T) {
        if (T.size() > S.size()) return "";
        string res = "";
        int left = 0, count = 0, minLen = S.size() + 1;
        unordered_map<char, int> m;
        for (int i = 0; i < T.size(); ++i) {
            if (m.find(T[i]) != m.end()) ++m[T[i]];
            else m[T[i]] = 1;
        }
        for (int right = 0; right < S.size(); ++right) {
            if (m.find(S[right]) != m.end()) {
                --m[S[right]];
                if (m[S[right]] >= 0) ++count;
                while (count == T.size()) {
                    if (right - left + 1 < minLen) {
                        minLen = right - left + 1;
                        res = S.substr(left, minLen);
                    }
                    if (m.find(S[left]) != m.end()) {
                        ++m[S[left]];
                        if (m[S[left]] > 0) --count;
                    }
                    ++left;
                }
            }
        }
        return res;
    }
};


/*
这道题也可以不用哈希表，直接用个int的数组来代替，因为ASCII只有256个字符，所以用两个大小为256的int数组即可代替哈希表，其余部分的思路完全相同，代码如下：
*/

class Solution {
public:
    string minWindow(string S, string T) {
        if (T.size() > S.size()) return "";
        string res = "";
        int left = 0, count = 0, minLen = S.size() + 1;
        int tm[256] = {0}, sm[256] = {0};
        for (int i = 0; i < T.size(); ++i) ++tm[T[i]];
        for (int right = 0; right < S.size(); ++right) {
            if (tm[S[right]] != 0) {
                ++sm[S[right]];
                if (sm[S[right]] <= tm[S[right]]) ++count;      
                while (count == T.size()) {
                    if (right - left + 1 < minLen) {
                        minLen = right - left + 1;
                        res = S.substr(left, minLen);
                    }
                    if (tm[S[left]] != 0) {
                        --sm[S[left]];
                        if (sm[S[left]] < tm[S[left]]) --count;
                    }
                    ++left;
                }
            }
        }
        return res;
    }
};
