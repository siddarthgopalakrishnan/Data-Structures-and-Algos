#include<stdio.h>
int bin[16],ans[16],cnt;
void tobin(int x,int n,int *arr)
{
  int cpy =x,t=0,cnt=0;
  while(cpy!=0)
  {
    arr[n-1-t]=cpy%2;
    cpy=cpy>>1;
    t++;
  }
  while(n-1-t>=0)
  {arr[n-1-t]=0;t++;}
}
int main()
{
  int n,k,t=0,l;
  scanf("%d %d",&n,&k);
  tobin(k,n,bin);
  for(int i=0;i<n;i++){if(bin[i]==0)cnt++;}
  l = (1<<cnt);
  for(int i=0;i<l;i++)
  {
    tobin(i,cnt,ans);
    t=0;
    for(int j=0;j<n;j++)
    {
      if(bin[j]==0)
        printf("%d",ans[t++]);
      else
        printf("1");
    }
    printf("\n");
  }
}