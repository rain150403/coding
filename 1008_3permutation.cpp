/*
时间限制：1秒 空间限制：32768K 
本题知识点： 字符串

题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
*/

//运行时间：1ms 占用内存：504K

class Solution{
public:
	vector<string> Permutation( string str ){
		vector<string> array;

		Permutation( array, str, 0 );
		sort( array.begin(), array.end() );
		return array;
	}

	void Permutation( vector<string> &array, string str, int begin ){
		if( begin == str.size()-1 ){
			array.push_back( str );  //每一轮递归到最后一个元素是压入
		}
		for( int i = begin; i < str.size(); ++i ){
			if( i != begin && str[i] == str[begin] )
				continue;
			swap( str[begin], str[i] );
			Permutation( array, str, begin+1 );
			swap( str[begin], str[i] );  //这一步很重要  例如 abc 第一次a,b交换  如果不二次交换 第二次再循环将b,c交换而不是a,c交换
		}
	}
};

