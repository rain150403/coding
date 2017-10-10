/*
时间限制：1秒 空间限制：32768K
本题知识点： 数组

题目描述
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/

//运行时间：1ms 占用内存：496K

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        int len = numbers.size();
		if( len == 0 )
			return "";
		sort( numbers.begin(), numbers.end(), cmp );
		string res;
		for( int i = 0; i < len; ++i ){
			res += to_string( numbers[i] );
		}
		return res;
    }
    
    static bool cmp( int a, int b ){
		string A = to_string(a) + to_string(b);
		string B = to_string(b) + to_string(a);
		return A < B;
	}
};
