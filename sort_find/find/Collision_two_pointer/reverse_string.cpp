/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".

这道题没什么难度，直接从两头往中间走，同时交换两边的字符即可，参见代码如下：
*/

class Solution {
public:
    string reverseString(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            char t = s[left];
            s[left++] = s[right];
            s[right--] = t;
        }
        return s;
    }
};

//使用swap
class Solution {
public:
    string reverseString(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left++], s[right--]);
        }
        return s;
    }
};


/*
reverse string 2

Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the 
string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k 
characters, then reverse the first k characters and left the other as original.

Example:

Input: s = "abcdefg", k = 2
Output: "bacdfeg"
 
Restrictions:

The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]
 

这道题是之前那道题Reverse String的拓展，同样是翻转字符串，但是这里是每隔k隔字符，翻转k个字符，最后如果不够k个了的话，剩几个就翻转几个。比较直接的
方法就是先用n／k算出来原字符串s能分成几个长度为k的字符串，然后开始遍历这些字符串，遇到2的倍数就翻转，翻转的时候注意考虑下是否已经到s末尾了，
参见代码如下：
*/

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size(), cnt = n / k;
        for (int i = 0; i <= cnt; ++i) {
            if (i % 2 == 0) {
                if (i * k + k < n) {
                    reverse(s.begin() + i * k, s.begin() + i * k + k);
                } else {
                    reverse(s.begin() + i * k, s.end());
                }
            }
        }
        return s;
    }
};

//每2k个字符来遍历原字符串s，然后进行翻转，翻转的结尾位置是取i+k和末尾位置之间的较小值

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            reverse(s.begin() + i, min(s.begin() + i + k, s.end()));
        }
        return s;
    }
};
