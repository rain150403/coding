/*
给定一个源串和目标串，能够对源串进行如下操作：

在给定位置上插入一个字符
替换任意字符
删除任意字符
写一个程序，返回最小操作数，使得对源串进行这些操作后等于目标串，源串和目标串的长度都小于2000。
*/

//dp[i,j]表示表示源串S[0…i] 和目标串T[0…j] 的最短编辑距离
dp[i, j] = min { dp[i - 1, j] + 1,  dp[i, j - 1] + 1,  dp[i - 1, j - 1] + (s[i] == t[j] ? 0 : 1) }
//分别表示：删除1个，添加1个，替换1个（相同就不用替换）。

//dp[i][j]表示源串source[0-i)和目标串target[0-j)的编辑距离
int EditDistance(char *pSource, char *pTarget)
{
	int srcLength = strlen(pSource);
	int targetLength = strlen(pTarget);
	int i, j;
	//边界dp[i][0] = i，dp[0][j] = j  
	for (i = 1; i <= srcLength; ++i)
	{
		dp[i][0] = i;
	}
	for (j = 1; j <= targetLength; ++j)
	{
		dp[0][j] = j;
	}
	for (i = 1; i <= srcLength; ++i)
	{
		for (j = 1; j <= targetLength; ++j)
		{
			if (pSource[i - 1] == pTarget[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[srcLength][targetLength];
}

******************************************************************************************************************************
#include <stdio.h>
#include <string.h>

char s1[1000], s2[1000];

int min( int a, int b, int c ){
	int tmp = a < b ? a : b;
	return tmp < c ? tmp : c;
}

void editDistance( int len1, int len2 ){
	int **d = new int*[len1 + 1];
	for( int i = 0; i <= len1; i++ )
		d[i] = new int[len2 + 1];
	int i, j;
	for( i = 0; i <= len1; i++ )
		d[i][0] = i;
	for( j = 0; j <= len2; j++ )
		d[0][j] = j;
	for( i= 1; i <= len1; i++ ){
		for( j = 1; j <= len2; j++ ){
			int cost = s1[i] == s2[j]?0:1;
			int deletion = d[i-1][j] + 1;
			int insertion = d[i][j-1] + 1;
			int substitution = d[i-1][j-1] + cost;
			d[i][j] = min(deletion, insertion, substitution );
		}
	}
	printf( "distance is: %d\n", d[len1][len2] );
	for( int i = 0; i <= len1; i++ ){
		delete[] d[i];
	}
	delete[] d;
}

int main(){
	while( scanf( "%s%s", s1, s2 ) != EOF ){
		editDistance( strlen(s1), strlen(s2) );
	}
}
