#include<stdio.h>
int arr[1000000],n,cnt=1,ans=1;
void swap(int *x,int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}
void insertion(int i)
{
  while(i>0&&arr[i]>arr[i-1])
  {swap(&arr[i],&arr[i-1]);i--;}
}
int main()
{
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);insertion(i);
  }
  for(int i=0;i<n-1;i++)
  {
    if(arr[i]!=arr[i+1])
      cnt++;
  }
  for(int i=0;i<n-1;i++)
  {
    ans+=cnt;
    if(arr[i]!=arr[i+1])
      cnt--;
  }
  printf("%d\n",ans);
}