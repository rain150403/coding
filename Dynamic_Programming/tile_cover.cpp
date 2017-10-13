/*
编程之美中题目：
某年夏天,位于希格玛大厦四层的微软亚洲研究院对办公楼的天井进行了一次大 规模的装修.原来的地板铺有 N×M 块正方形瓷砖,这些瓷砖都已经破损老化了,需要予以 
更新.装修工人们在前往商店选购新的瓷砖时,发现商店目前只供应长方形的瓷砖,现在的 一块长方形瓷砖相当于原来的两块正方形瓷砖, 工人们拿不定主意该买多少了,
读者朋友们 请帮忙分析一下:能否用 1×2 的瓷砖去覆盖 N×M 的地板呢?
*/
//这个题目类属于状态压缩DP，对于状态压缩DP，其实最简单的理解就是把状态用比特位的形式表示出来。

//方法一：

/*#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <algorithm>

using namespace std;

#define MAX_ROW 11
#define MAX_STATUS 2048
long long DP[MAX_ROW][MAX_STATUS];
int g_Width, g_Height;

bool TestFirstLine( int nStatus )//test the first line
{
    int i = 0;
    while( i < g_Width ){
        if( nStatus & ( 0x1 << i ) ){
            if( i == g_Width - 1 || ( nStatus & ( 0x1 << ( i + 1 ) ) ) == 0 ){
                return false;
            }
            i += 2;
        }
        else
        {
            i++;
        }
    }
    return true;
}

bool CompatablityTest( int nStatusA, int nStatusB ) { // test if status ( i, nStatusA ) and ( i - 1, nStatusB ) is compatable.
    int i = 0;
    while( i < g_Width ){
        if( ( nStatusA & ( 0x1 << i ) ) == 0 ){
            if( ( nStatusB & ( 0x1 << i ) ) == 0 ){
                return false;
            }
            i++;
        }
        else{
            if( ( nStatusB & ( 0x1 << i ) ) == 0 ){
                i++;
            }
            else if( ( i == g_Width - 1 ) || !( ( nStatusA & ( 0x1 << ( i+1 ) ) ) && ( nStatusB & ( 0x1 << ( i+1 ) ) ) ) ){
                return false;
            }
            else{
                i += 2;
            }
        }
    }

    return true;
}

int main(){
    int i, j;
    int k;
    while( scanf( "%d%d", &g_Height, &g_Width ) != EOF ){
        if( g_Width == 0 && g_Height == 0 ){
            break;
        }

        if( g_Width > g_Height ){
            swap( g_Width, g_Height );
        }

        int nAllStatus = 2 << ( g_Width-1 );
        memset( DP, 0, sizeof(DP) );
        for( j = 0; j < nAllStatus; j++ ){
            if( TestFirstLine(j) ){
                DP[0][j] = 1;
            }
        }

        for( i = 1; i < g_Height; i++ ){
            for( j = 0; j < nAllStatus; j++ ){ // iterate all status for line i
                for( k = 0; k < nAllStatus; k++ ){ // iterate all status for line i-1
                    if( CompatablityTest(j, k) ){
                        DP[i][j] += DP[i-1][k];
                    }
                }
            }
        }

        printf( " %lld\n", DP[g_Height-1][nAllStatus-1] );
    }

    return 0;
}*/

/*
瓷砖覆盖（状态压缩DP）

难度评级：★★★

用1*2的瓷砖覆盖n*m的地板，问共有多少种覆盖方式？

解法：
	分析子结构，按行铺瓷砖。一块1*2瓷砖，横着放对下一行的状态没有影响；竖着放时，下一行的对应一格就会被占用。因此，考虑第i行的铺法时只需考虑由第i-1行
  造成的条件限制。枚举第i-1行状态即可获得i行可能的状态，这里为了与链接一文一致，第i-1行的某格只有两个状态：空着或者放置。空表示第i行对应位置需要放置
  一个竖着的瓷砖，这时在铺第i行时， 除去限制以外，只需考虑放还是不放横着的瓷砖这2种情况即可（不必分为放还是不放，横到下一层还是竖着一共四种）。
  同时对于第i-1行的放法， 用二进制中的0和1表示有无瓷砖，那么按位取反恰好就是第i行的限制条件。

*/
//方法二：

#include <stdio.h>
#include <string.h>

int n, m;
long long dp[12][2049];  ///64

void dfs( int row, int state, int pos, long long pre_num ){  ///64

    if( pos == m ) {
        dp[row][state] += pre_num;
        return;
    }

    dfs( row, state, pos+1, pre_num );

    if( ( pos <= m-2 ) && !( state & ( 1 << pos ) ) && !( state & ( 1 << ( pos + 1 ) ) ) )
        dfs( row, state | ( 1 << pos ) | ( 1 << ( pos + 1 ) ), pos + 2, pre_num );
}

int main(){
    while( scanf( "%d%d", &n, &m ) && ( n || m ) ){
        if( n < m ){
            n = n ^ m;
            m = n ^ m;
            n = n ^ m;
        }

        memset( dp, 0, sizeof( dp ) );

        dfs( 1, 0, 0, 1 );

        for( int i = 2; i <= n; i++ )
            for( int j = 0; j < ( 1 << m ); j++ ){
                if( dp[i-1][j] ){
                    long long tmp = dp[i-1][j];   ///int64

                    dfs( i, (~j) & ( ( 1 << m ) - 1 ), 0, tmp );
                }
                else
                    continue;
            }

        printf( "%lld\n", dp[n][( 1 << m ) - 1] );  ///64
    }

    return 0;
}


//结果：
/*********************************************/
/*
/home/wmm/CLionProjects/hiho30/cmake-build-debug/hiho30
1 2
1
2 3
3
3 4
11
4 5
95
5 6
1183
6 7
31529
7 8
1292697
8 9
108435745
9 10
14479521761
10 11
3852472573499
11 12

Process finished with exit code 139 (interrupted by signal 11: SIGSEGV)

*/
/************************************************************/
