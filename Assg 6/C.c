#include<stdio.h>
#include<string.h>
char stack[500000];
char str[500000];
int main()
{
    scanf("%s",str);
    int p=0;
    int len = strlen(str);;
    for(int i=0;i<len;i++)
    {
        if(str[i]=='('||str[i]=='+'||str[i]=='-'||str[i]=='%'||str[i]=='*'||str[i]=='/')
        {
            stack[p++]=str[i];
        }
        else if(str[i]==')')
        {
            while(p>=1&&stack[p-1]!='(')
            {
                printf("%c",stack[p-1]);
                p--;
            }
            if(p>0) p--;
        }
        else printf("%c",str[i]);
    }
    printf("\n");
}