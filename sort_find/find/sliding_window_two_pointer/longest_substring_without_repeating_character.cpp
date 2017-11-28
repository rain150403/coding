/*
在滑动窗口中做记录

题目：在一个字符串中寻找没有重复的最长子串，返回长度

就是一个窗口，r先走，l落后
*/

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int freq[256] = {0};

        int l = 0, r = -1; //滑动窗口为s[l...r]
        int res = 0;

        while( l < s.size() ){

            if( r + 1 < s.size() && freq[s[r+1]] == 0 )
                freq[s[++r]] ++;
            else    //r已经到头 || freq[s[r+1]] == 1
                freq[s[l++]] --;

            res = max( res , r-l+1);
        }

        return res;
    }
};

int main() {

    cout << Solution().lengthOfLongestSubstring( "abcabcbb" )<<endl;
    cout << Solution().lengthOfLongestSubstring( "bbbbb" )<<endl;
    cout << Solution().lengthOfLongestSubstring( "pwwkew" )<<endl;
    cout << Solution().lengthOfLongestSubstring( "" )<<endl;

    return 0;
}

///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// 滑动窗口的另一个实现, 仅做参考
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int freq[256] = {0};

        int l = 0, r = -1;
        int res = 0;

        while( r + 1 < s.size() ){

            while( r + 1 < s.size() && freq[s[r+1]] == 0 )
                freq[s[++r]] ++;

            res = max( res , r-l+1);

            if( r + 1 < s.size() ){
                freq[s[++r]] ++;
                assert( freq[s[r]] == 2 );
                while( l <= r && freq[s[r]] == 2 )
                    freq[s[l++]] --;
            }
        }

        return res;
    }
};

int main() {

    cout << Solution().lengthOfLongestSubstring( "abcabcbb" )<<endl;
    cout << Solution().lengthOfLongestSubstring( "bbbbb" )<<endl;
    cout << Solution().lengthOfLongestSubstring( "pwwkew" )<<endl;
    cout << Solution().lengthOfLongestSubstring( "" )<<endl;

    return 0;
}
