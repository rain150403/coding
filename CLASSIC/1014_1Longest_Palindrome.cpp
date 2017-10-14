/*

[编程题]最长回文子串
时间限制：3秒空间限制：32768K

对于一个字符串，请设计一个高效算法，计算其中最长回文子串的长度。给定字符串A以及它的长度n，请返回最长回文子串的长度。

测试样例：
"abc1234321ab",12
返回：7

*/

class Palindrome {
public:
    int getLongestPalindrome(string A, int n) {
        // write code here
        int i, j, max, c;
        if ( n < 1)
            return 0;
        max = 0;
        
        for (i = 0; i < n; ++i) { // i is the middle point of the palindrome  
            for (j = 0; (i - j >= 0) && (i + j < n); ++j){ // if the length of the palindrome is odd  
                if (A[i - j] != A[i + j])
                    break;
                c = j * 2 + 1;
            }
            
            if (c > max)
                max = c;
            for (j = 0; (i - j >= 0) && (i + j + 1 < n); ++j){ // for the even case  
                if (A[i - j] != A[i + j + 1])
                    break;
                c = j * 2 + 2;
            }
            if (c > max)
                max = c;
        }
        return max;
    }
};
