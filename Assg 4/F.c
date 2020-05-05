#include<stdio.h>
int n,arr[1000000],p;
void swap(int *x,int *y)
{
    int temp =*x;
    *x = *y;
    *y = temp;
}
void segregate(int pivot)
{
    int low = 0;
    int high = n-1;
    while(low<high)
    {
        while(pivot>arr[low]){low++;}
        while(pivot<arr[high]){high--;}
        if(low!=high&&arr[low]==arr[high])
        {
            high--;
            while(pivot<arr[high]){high--;}
        }
        if(low<high){swap(&arr[low],&arr[high]);}
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){scanf("%d",&arr[i]);}
    scanf("%d",&p);
    int i,flag=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]>p)
        break;
    }
    for(int j=i;j<n;j++)
        if(arr[j]<=p){
            flag=1;break;
        }
    if(flag==0)
        printf("ALL SET\n");
    else
    {
        segregate(p);
        for(int i=0;i<n;i++)
            printf("%d ",arr[i]);
    }
}