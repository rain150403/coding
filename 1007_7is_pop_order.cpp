/*
时间限制：1秒 空间限制：32768K
本题知识点： 栈

题目描述
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
*/

//运行时间：1ms 占用内存：500K

class Solution{
public:
	bool IsPopOrder( vector<int> pushV, vector<int> popV ){
		stack<int> st;
		int id = 0;
		for( int i = 0; i < popV.size(); ++i ){
			while( st.empty() || st.top() != popV[i] ){
				st.push( pushV[id++] );
				if( id > pushV.size() ){
					return false;
				}
			}
			st.pop();
		}	
		if( st.empty() )
			return true;
		else
			return false;
	}
};
