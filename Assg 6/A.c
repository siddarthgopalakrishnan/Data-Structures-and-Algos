#include<stdio.h>
#include<string.h>
char str[3000000];
int stack[3000000];
int main()
{
    scanf("%s",str);
    int len = strlen(str);
    int j=1,x;
    stack[0]=(int)str[0];
    for(int i=1;i<len;i++)
    {
        if(str[i]==str[i-1])
        {
            while(str[i]==str[i-1])
                i++;
            i--;
        }
        x = str[i];
        if(x == stack[j-1]&&x!=str[i+1])
        {
            j--;
        }
        else if(x!=stack[j-1])
        {
            stack[j++]=x;
        } 
    }
    if(j==0)
        printf("VANISHED");
    else
    {
        for(int i=0;i<j;i++)
        printf("%c",stack[i]);
        printf("\n");
    }
}