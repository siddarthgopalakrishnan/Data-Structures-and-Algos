#include<stdio.h>
int arr[100000];
int main()
{
  int n,k;
  scanf("%d %d",&n,&k);
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  int st=0,end=1,ans=0;
  while(end<n)
  {
    while(end<n&&arr[end]-arr[st]<=k)
      end++;
    if(end-st-2>0)
      ans+= ((end-st-1)*(end-st-2))/2;
    st++;
  }
  while(end-st-2>0)
    {ans+= ((end-st-1)*(end-st-2))/2;st++;}
  printf("%d\n",ans);
}