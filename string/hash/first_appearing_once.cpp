/*
题目描述

请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六
个字符“google"时，第一个只出现一次的字符是"l"。 
输出描述:

如果当前字符流没有存在出现一次的字符，返回#字符。
*/

class Solution{
public:
	int occurrence[256];// 利用数组occurrence构造哈希表，将字符的ASCII值作为键值， 将字符对应的位置作为哈希值
	int index;
	Solution():index(0){
		for( int i = 0; i < 256; ++i )
			occurrence[i] = -1; // 所有元素初始化为-1
	}

	void Insert( char ch ){
		if( occurrence[ch] == -1 ) // 当ASCII为ch的字符第一次从字符流中读出时， occurrence[ch]更新为它在字符流中的位置
			occurrence[ch] = index;
		else if ( occurrence[ch] >= 0 )
			occurrence[ch] = -2; //当该字符再次从字符流中读出时，更新为-2

		index++;
	}

	char FirstAppearingOnce(){
		char ch = '#';
		int minIndex = INT_MAX;
		// 遍历数组，找出最小的大于等于0的值对应的字符，就是所求的目前从字符流中读出所有字符中第一个不重复的字符
		for( int i = 0; i < 256; ++i ){
			if( occurrence[i] >= 0 && occurrence[i] < minIndex ){
				ch = ( char )i;
				minIndex = occurrence[i];  //返回的是索引，不是个数。
			}
		}

		return ch;
	}
};
