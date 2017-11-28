/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

这道题让我们翻转字符串中的元音字母，元音字母有五个a,e,i,o,u，需要注意的是大写的也算，所以总共有十个字母。我们写一个isVowel的函数来判断当前字符是否为
元音字母，如果两边都是元音字母，那么我们交换，如果左边的不是，向右移动一位，如果右边的不是，则向左移动一位，参见代码如下：
*/

//方法一：
class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right= s.size() - 1;
        while (left < right) {
            if (isVowel(s[left]) && isVowel(s[right])) {
                swap(s[left++], s[right--]);
            } else if (isVowel(s[left])) {
                --right;
            } else {
                ++left;
            }
        }
        return s;
    }
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};

//方法二： 或者我们也可以用自带函数find_first_of和find_last_of来找出包含给定字符串中任意一个字符的下一个位置进行交换即可：
class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            left = s.find_first_of("aeiouAEIOU", left);
            right = s.find_last_of("aeiouAEIOU", right);
            if (left < right) {
                swap(s[left++], s[right--]);
            }
        }
        return s;
    }
};

//方法三：我们也可以把元音字母都存在一个字符串里，然后每遇到一个字符，就到元音字符串里去找，如果存在就说明当前字符是元音字符，参见代码如下：

class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        string t = "aeiouAEIOU";
        while (left < right) {
            if (t.find(s[left]) == string::npos) ++left;
            else if (t.find(s[right]) == string::npos) --right;
            else swap(s[left++], s[right--]);
        }
        return s;
    }
};
