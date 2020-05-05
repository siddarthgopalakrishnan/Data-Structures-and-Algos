#include<stdio.h>
long mod = 1000000007;
int main()
{
  long n,arr[1000],sum=0,cnt;
  scanf("%ld",&n);
  for(long i=0;i<n;i++)
  {
    scanf("%ld",&arr[i]);
  }
  for(long i=0;i<32;i++)
  {
    cnt =0;
    for(long j=0;j<n;j++)
    {
      if(arr[j] & 1<<i)
        cnt++;
    }
    sum += 2*(((cnt % mod)*((n-cnt)%mod))%mod);
  }
  printf("%ld\n",sum);
}