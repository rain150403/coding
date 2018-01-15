/*
题目描述

请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六
个字符“google"时，第一个只出现一次的字符是"l"。 
输出描述:

如果当前字符流没有存在出现一次的字符，返回#字符。

解法：
/*
读到题目，会有一个初步的思路，再近一步完善。
想到我们需要一个数据容器，可以统计每个字符在该字符串中出现的次数。
哈希表，键值key是字符，而值value是该字符出现的次数。
我们创建一个长度为256的数组，每个字母根据其ASCII码值作为数组的下标对应数组的一个数字，而数组中存储的是每个字符出现的次数。
第一次扫描，在哈希表中更新一个字符出现的次数
第二次扫描，读出一个字符出现的次数。
*/
*/
char FirstNotRepeatingChar(char* pString){
	if(pString == NULL)
		return '\0';
	const int tableSize = 256;
	unsigned int hashTable[tableSize];
	for(unsigned int i = 0; i < tableSize; ++i)
		hashTable[i] = 0;

	char* pHashKey = pString;
	while(*(pHashKey) != '\0')
		hashTable[*(pHashKey++)]++;

	pHashKey = pString;
	while(*pHashKey != '\0'){
		if(hashTable[*pHashKey] == 1)
			return *pHashKey;

		pHashKey++;
	}

	return '\0';
}
####################################################################

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
