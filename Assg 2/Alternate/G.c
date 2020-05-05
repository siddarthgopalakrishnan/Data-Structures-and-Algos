#include<stdio.h>
#include<string.h>
char s[1000000];
int main()
{
    int best = 1;
    int ans=0;
    scanf("%s",s);
    int n = strlen(s);
    int l;

    for(int i=0;i<n;i++)
    {
        for(l=0;i-l>=0&&i+l<n;l++)
        {
            if(s[i+l]!=s[i-l])
                break;
        }
        l--;
        if(best<2*l+1)
        {
            best = 2*l +1;
            ans = i-l;
        }
    }

    for(int i=1;i<n-1;i++)
    {
        for(l=1;i-l>=0&&l+i-1<n;l++)
        {
            if(s[i-l]!=s[l+i-1])
                break;
        }
        l--;
        if(best<2*l)
        {
            best = 2*l;
            ans = i-l;
        }
    }
    printf("%d\n",best);
    for(int i=0;i<best;i++)
    {
        printf("%c",s[ans+i]);
    }
}
