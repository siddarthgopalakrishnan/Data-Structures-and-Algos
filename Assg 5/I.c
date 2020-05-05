#include<stdio.h>
#include<limits.h>
int arr[3000000];
int n,k;
void swap(int *x,int *y)
{
  int temp = *x;
  *x=*y;
  *y=temp;
}
void insertion(int i)
{
  while(i>0&&arr[i]<arr[i-1])
  {
    swap(&arr[i],&arr[i-1]);
    i--;
  }
}
int main()
{
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
    insertion(i);
  }
  scanf("%d",&k);
  int flg=0,ans1,ans2;
  for(int i=0;i<n;i++)
  {
    int left = i,mid,flag=0;
    int right = n-1;
    int rem = k-arr[left];
    left++;
    while(left<=right)
    {
      mid=(left+right)/2;
      if(arr[mid]==rem){flag=1;break;}
      else if(arr[mid]<rem){left=mid+1;}
      else if(arr[mid>rem]){right=mid-1;}
    }
    if(flag==1)
    {
      ans1=arr[i];ans2=arr[mid];
      if(flg==0)
      {printf("YES\n");flg=1;}
    }
  }
  if(flg==1)
  {
    printf("%d %d\n",ans1,ans2);
  }
  else {printf("NO\n");}
}