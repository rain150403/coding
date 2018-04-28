/*一般都是获得文件的全名，然后自己解析文件的后缀。比如从后往前遍历，遇到第一个'.'字符就停止，那么后面的就是后缀名咯。*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_extension(const char *file_name,char *extension)
{
        int i=0,length;
        length=strlen(file_name);
        while(file_name[i])
        {
                if(file_name[i]=='.')
                        break;
                i++;
        }
        if(i<length)
                strcpy(extension,file_name+i+1);
        else
                strcpy(extension,"\0");
}

int main()
{
        char  a[20],b[10],ch;
        int i=0;
        while((ch=getchar())!='\n')
        {
                a[i++]=ch;
                if(i>=20)
                        break;
        }
        a[i]='\0';
        get_extension(a,b);
        printf("%s\n",b);
        //getch();
}
