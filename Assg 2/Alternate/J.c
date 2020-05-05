#include<stdio.h>
#include<math.h>
int main()
{
    long long int num,ans=0,n;
    scanf("%lld",&num);
    n=num;
    if(num%2==0)
    {
        ans = ans^2;
        while(num%2==0)
        num=num/2;
    }
    for(int i=3;i<=sqrt(n);i=i+2)
    {
        if(num%i==0)
        {
            printf("%d\n",i);
            ans = ans^i;
            while(num%i==0)
                num=num/i;
        }
        if(num<i)
            break;
    }
    printf("%lld",ans^num);
}
