#include<stdio.h>
#include<string.h>
char str[5000000];
char stack[500000];
int main()
{
    scanf("%s",str);
    int len = strlen(str);
    int k =-1;
    for(int i=0;i<len;i++)
    {
        if(str[i]=='['||str[i]=='('||str[i]=='{')
        {
            stack[++k]=str[i];
        }
        else
        {
            if(k<0)
            {printf("NO\n");return 0;}
            else
            {
                if((str[i]=='}'&&stack[k]=='{')||(str[i]==']'&&stack[k]=='[')||(str[i]==')'&&stack[k]=='('))
                    k--;
                else
                {printf("NO\n");return 0;}
            }
        }
    }
    if(k!=-1)
        printf("NO\n");
    else
        printf("YES\n");
    
}