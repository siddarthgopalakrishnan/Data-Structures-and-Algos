#include<stdio.h>
int arr[10000][10000],k;
int main()
{
  int n,m,flag=0;
  scanf("%d %d",&n,&m);
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
      scanf("%d",&arr[i][j]);
  }
  scanf("%d",&k);
  int currx=0,curry=m-1;
  while(currx<n||curry>=0)
  {
      if(arr[currx][curry]==k){flag=1;break;}
      else if(arr[currx][curry]<k)currx++;
      else if(arr[currx][curry]>k)curry--;
  }
  if(flag==1) printf("YES\n%d %d\n",currx,curry);
  else printf("MISSING\n");
}