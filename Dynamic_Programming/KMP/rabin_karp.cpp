//虽然输出很多数，但依然能一眼看出那个起始位置

//转自：http://blog.csdn.net/u011467044/article/details/55008649

#include"stdio.h"
#include"string.h"
#include"math.h"
#include <stdlib.h>

char*  substr(char* p,int start,int end)
{
        char *q;
        q=(char *)malloc(sizeof(char)*(end-start+1));
        int i;
        for(i=0;i<end-start+1;i++)
             *(q+i)=*(p+start+i);
       // *(q+end-start+1)='\0';
        return q;
}//取T中T[s+1,s+m]子字符串
void RABIN_KARP_MATCHER(char T[],char P[],int d,int q)
{
    int n,m,h,p,t,i,t0=0;
    n=strlen(T);
    m=strlen(P);
   h=((int)pow(d,m-1));
  // h=((int)pow(d,m-1))%q;//取模运算
    p=0;
    t=0;
    for(i=0;i<m;i++)
    {
        p=(d*p+P[i]-'a')%q;//求p
        t =(d*t +T[i]-'a')%q;
        t0=(d*t0 +T[i]-'a');//求初始t0=num(T[1,m])
    }
    int s;
    for(s=0;s<=n-m;s++)
    {
            if(p==t&&(strcmp(P,substr(T,s,s+m-1))==0))
         //  if(p==t)
           {

                printf("%d\n",s);
           }

           printf("%d  %d  %c \n",t,p,T[s]);
           int tem=t0;
           t0=(d*(tem-(T[s]-'a')*h)+T[s+m]-'a');//求ts+1;
           t=t0%q;
  //              int tem=t;
   //             t=(d*(tem-(T[s]-'a')*h)+T[s+m]-'a')%q;

    }
}
int main()
{

        char T[100], P[100];
        scanf("%s",T);
        scanf("%s",P);
        RABIN_KARP_MATCHER(T,P,10,13);

        return 0;
}
