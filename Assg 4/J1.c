#include<stdio.h>
#include<stdlib.h>
long double abs1(long double t)
{
  if(t<0) return -t;
  else return t;
}
long long int mysqrt(unsigned long long int x)
{
    long double t = x;
    long double i = 1, epsilon=0.1;
    while(abs1(x-i*i) > epsilon)
        i=((i*i) + t)/(2*i);
    return (long long int)i;
}
int main()
{
    int q;
    unsigned long long int x;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%llu",&x);
        printf("%llu\n",mysqrt(x));
    }
}