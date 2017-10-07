/*
时间限制：1秒 空间限制：32768K
本题知识点： 数组

题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

//运行时间：1ms 占用内存：504k

class Solution{
public:
	vector<int> printMatrix( vector<vector<int>> matrix ){
		
		vector<int> res;
		
		int n = matrix.size();
		int m = matrix[0].size();
		int layer = (min(m, n) - 1)/2+1;
		for( int i = 0; i < layer; i++ ){
			for( int j = i; j < m-i; j++ ){
				res.push_back(matrix[i][j]);
			}
			for( int k = i+1; k < n-i; k++ ){
				res.push_back( matrix[k][m-i-1] );
			}
			for( int p = m-i-2; (p > i - 1) && (n-i-1!=i); p-- ){
				res.push_back( matrix[n-i-1][p]);
			}
			for( int q = n-i-2; ( q>i )&&(m-i-1 != i); q-- ){
				res.push_back(matrix[q][i]);
			}
		}
		return res;
	}
};
