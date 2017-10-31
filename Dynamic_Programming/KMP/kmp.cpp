//转自：http://blog.csdn.net/u011564456/article/details/20862555

#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#define N 100  
  
void cal_next( char * str, int * next, int len )  
{  
    int i, j;  
  
    next[0] = -1;  
    for( i = 1; i < len; i++ )  
    {  
        j = next[ i - 1 ];  
        while( str[ j + 1 ] != str[ i ] && ( j >= 0 ) )  
        {  
            j = next[ j ];  
        }  
        if( str[ i ] == str[ j + 1 ] )  
        {  
            next[ i ] = j + 1;  
        }  
        else  
        {  
            next[ i ] = -1;  
        }  
    }  
}  
  
int KMP( char * str, int slen, char * ptr, int plen, int * next )  
{  
    int s_i = 0, p_i = 0;  
  
    while( s_i < slen && p_i < plen )  
    {  
        if( str[ s_i ] == ptr[ p_i ] )  
        {  
            s_i++;  
            p_i++;  
        }  
        else  
        {  
            if( p_i == 0 )  
            {  
                s_i++;  
            }  
            else  
            {  
                p_i = next[ p_i - 1 ] + 1;  
            }  
        }  
    }  
    return ( p_i == plen ) ? ( s_i - plen ) : -1;  
}  
  
int main()  
{  
    char str[ N ] = {0};  
    char ptr[ N ] = {0};  
    int slen, plen;  
    int next[ N ];  
  
    while( scanf( "%s%s", str, ptr ) )  
    {  
        slen = strlen( str );  
        plen = strlen( ptr );  
        cal_next( ptr, next, plen );  
        printf( "%d\n", KMP( str, slen, ptr, plen, next ) );  
    }  
    return 0;  
}  
////////////////////////////////////////////////////////////////////////////////////////////////

//转自：http://blog.csdn.net/u011467044/article/details/55008649

#include<stdio.h>
#include<string.h>
#define MAX_LEN 20
int PI[MAX_LEN];

void Compute_prefix_fun(char P[])
{
    int m,k,q;
    m=strlen(P);
    PI[0]=0;
    k=0;
    for(q=1;q<m;++q)
    {
        while((k>0)&&P[k]!=P[q])
        {
            //q=PI[q];
            k=PI[k];
        }
        if(P[k]==P[q])
            k=k+1;

        PI[q]=k;
    }

}
void  KMP_matcher(char T[],char P[])
{
    int n,m,q,i;
    n=strlen(T);
    m=strlen(P);
    Compute_prefix_fun(P);
    q=0;
    for(i=0;i<n;i++)
    {
        while((q>0)&&P[q]!=T[i])
        {
            q=PI[q-1];
        }
        if(P[q]==T[i])
            q=q+1;
        if(q==m)
        {
            printf("%d\n",i-m+1);
            q=PI[q-1];
        }

    }

}
int main()
{


    char T[20],P[20];
    scanf("%s",T);
    scanf("%s",P);
    KMP_matcher(T,P);
    return 0;
}
