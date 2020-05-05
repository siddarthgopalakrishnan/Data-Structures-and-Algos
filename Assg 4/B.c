#include<stdio.h>
int arr[100000][2];
void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void insertion(int last)
{
    while(last>0&&arr[last][0]<arr[last-1][0])
    {
        swap(&arr[last][0],&arr[last-1][0]);
        swap(&arr[last][1],&arr[last-1][1]);
        last--;
    }
}
int main()
{
    int n,k,sum=0,sumc=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&k);
        sumc +=k;
        arr[i][0]=k;
        arr[i][1]=i+1;
        insertion(i);
    }
    scanf("%d",&k);
    if(sumc<k)
        printf("NO CHANCE\n");
    else
    {
        for(int i=0;i<n;i++)
        {
            sum = sum + arr[i][0];
            printf("%d ",arr[i][1]);
            if(sum>=k) break;
        }
    }
}