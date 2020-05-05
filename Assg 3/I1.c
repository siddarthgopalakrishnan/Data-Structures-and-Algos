#include<stdio.h>
int input[1001],freq[10];
void print()
{
  for(int i=9;i>=0;i--)
  {
    for(int j=0;j<freq[i];j++)
    {
      printf("%d",i);
    }
  }
  printf("\n");
}
int main()
{
  int n,flag=0,sum=0;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    scanf("%d",&input[i]);
    sum = sum + input[i];
    freq[input[i]]++;
    if(input[i]==0)
        flag=1;
  }
  if(flag==0)
  {
    printf("NO NUMBER\n");
    return 0;
  }
  else
  {
    flag=-1;
    int mod = sum%3;
    if(mod==0)
    {
      print();
      return 0;
    }
    else
    {
      for(int i=mod;i<9;i=i+3)
      {
        if(freq[i]>0)
        {
          freq[i]--;
          flag=2;
          break;
        }
      }
      if(flag==2)
      {
        print();
        return 0;
      }
      else
      {
        for(int i=3-mod;i<9;i=i+3)
        {
          if(freq[i]>1)
          {
            freq[i]=freq[i]-2;
            flag=3;
            break;
          }
        }
        if(flag==3)
        {
          print();
          return 0;
        }
        else
        {
          printf("NO NUMBER\n");
          return 0;
        }
      }
    }
  }
}