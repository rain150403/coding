//一种是常规解法（先翻转整体，再翻转局部），一种使用字符流

/*
题目一：

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Clarification:

What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
 

这道题让我们翻转字符串中的单词，题目中给了我们写特别说明，如果单词之间遇到多个空格，只能返回一个，而且首尾不能有单词，并且对C语言程序员要求空间复杂度
为O(1)，所以我们只能对原字符串s之间做修改，而不能声明新的字符串。那么我们如何翻转字符串中的单词呢，我们的做法是，先整个字符串整体翻转一次，然后再分别
翻转每一个单词（或者先分别翻转每一个单词，然后再整个字符串整体翻转一次），此时就能得到我们需要的结果了。那么这里我们需要定义一些变量来辅助我们解题，
storeIndex表示当前存储到的位置，n为字符串的长度。我们先给整个字符串反转一下，然后我们开始循环，遇到空格直接跳过，如果是非空格字符，我们此时看
storeIndex是否为0，为0的话表示第一个单词，不用增加空格；如果不为0，说明不是第一个单词，需要在单词中间加一个空格，然后我们要找到下一个单词的结束位置
我们用一个while循环来找下一个为空格的位置，在此过程中继续覆盖原字符串，找到结束位置了，下面就来翻转这个单词，然后更新i为结尾位置，最后遍历结束，
我们剪裁原字符串到storeIndex位置，就可以得到我们需要的结果，代码如下：
*/
//方法一：
class Solution {
public:
    void reverseWords(string &s) {
        int storeIndex = 0, n = s.size();
        reverse(s.begin(), s.end());
        for (int i = 0; i < n; ++i) {
            if (s[i] != ' ') {
                if (storeIndex != 0) s[storeIndex++] = ' ';
                int j = i;
                while (j < n && s[j] != ' ') s[storeIndex++] = s[j++];
                reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
                i = j;
            }
        }
        s.resize(storeIndex);
    }
};

//方法二：
/*下面我们来看使用字符串流类stringstream的解法，我们先把字符串装载入字符串流中，然后定义一个临时变量tmp，然后把第一个单词赋给s，这里需要注意的是，如果
含有非空格字符，那么每次>>操作就会提取连在一起的非空格字符，那么我们每次将其加在s前面即可；如果原字符串为空，那么就不会进入while循环；如果原字符串为
许多空格字符连在一起，那么第一个>>操作就会提取出这些空格字符放入s中，然后不进入while循环，这时候我们只要判断一下s的首字符是否为空格字符，是的话就将s
清空即可，参见代码如下：*/
class Solution {
public:
    void reverseWords(string &s) {
        istringstream is(s);
        string tmp;
        is >> s;
        while(is >> tmp) s = tmp + " " + s;
        if(!s.empty() && s[0] == ' ') s = "";
    }
};

//方法三:
/*
下面这种方法也是使用stringstream来做，但是我们使用了getline来做，第三个参数是设定分隔字符，我们用空格字符来分隔，这个跟上面的>>操作是有不同的，每次
只能过一个空格字符，如果有多个空格字符连在一起，那么t会赋值为空字符串，所以我们在处理t的时候首先要判断其是否为空，是的话直接跳过，参见代码如下：
*/

class Solution {
public:
    void reverseWords(string &s) {
        istringstream is(s);
        s = "";
        string t = "";
        while (getline(is, t, ' ')) {
            if (t.empty()) continue;
            s = (s.empty() ? t : (t + " " + s));
        }
    }
};

/*
题目二：

Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.
The input string does not contain leading or trailing spaces and the words are always separated by a single space.
For example,
Given s = "the sky is blue",
return "blue is sky the".
Could you do it in-place without allocating extra space?

这道题让我们翻转一个字符串中的单词，跟之前那题Reverse Words in a String没有区别，由于之前那道题我们就是用in-place的方法做的，而这道题反而更简化了
题目，因为不考虑首尾空格了和单词之间的多空格了，方法还是很简单，先把每个单词翻转一遍，再把整个字符串翻转一遍，或者也可以调换个顺序，先翻转整个字符串，
再翻转每个单词，参见代码如下：
*/
class Solution {
public:
    void reverseWords(string &s) {
        int left = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s, left, i - 1);
                left = i + 1;
            }
        }
        reverse(s, 0, s.size() - 1);
    }
    void reverse(string &s, int left, int right) {
        while (left < right) {
            char t = s[left];
            s[left] = s[right];
            s[right] = t;
            ++left; --right;
        }
    }
};

/*
题目三：

Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and 
initial word order.

Example 1:

Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
 
Note: In the string, each word is separated by single space and there will not be any extra space in the string.

这道题让我们翻转字符串中的每个单词，感觉整体难度要比之前两道Reverse Words in a String II和Reverse Words in a String要小一些，由于题目中说明了
没有多余空格，使得难度进一步的降低了。首先我们来看使用字符流处理类stringstream来做的方法，相当简单，就是按顺序读入每个单词进行翻转即可，参见代码如下：
*/

//方法一：
class Solution {
public:
    string reverseWords(string s) {
        string res = "", t = "";
        istringstream is(s);
        while (is >> t) {
            reverse(t.begin(), t.end());
            res += t + " ";
        }
        res.pop_back();
        return res;
    }
};

//方法二：
/*
下面我们来看不使用字符流处理类，也不使用STL内置的reverse函数的方法，那么就是用两个指针，分别指向每个单词的开头和结尾位置，确定了单词的首尾位置后，
再用两个指针对单词进行首尾交换即可，有点像验证回文字符串的方法，参见代码如下：
*/

class Solution {
public:
    string reverseWords(string s) {
        int start = 0, end = 0, n = s.size();
        while (start < n && end < n) {
            while (end < n && s[end] != ' ') ++end;
            for (int i = start, j = end - 1; i < j; ++i, --j) {
                swap(s[i], s[j]);
            }
            start = ++end;
        }
        return s;
    }
};
