#include<stdio.h>
int arr[200000],copy[200000];
int merge(int l,int mid,int r)
{
    int left = l;
    int right = mid+1;
    int cnt=0,k=0,delta=0;
    while(left<=mid&&right<=r)
    {
        if(arr[left]>arr[right])
        {
            delta = right - mid;
            copy[k++]=arr[right++];
        }
        else
        {
            copy[k++]=arr[left++];
            cnt = cnt + delta;
        }
    }
    while(left<=mid)
    {
        copy[k++]=arr[left++];
        cnt = cnt+delta;
    }
    while(right<=r)
    {
        copy[k++]=arr[right++];
    }
    k=0;
    for(int i=l;i<=r;i++)
    {
        arr[i]=copy[k++];
    }
    return cnt;
}
int mergesort(int l,int r)
{
    if(l>=r)
        return 0;
    int mid = (l+r)/2;
    int left = mergesort(l,mid);
    int right = mergesort(mid+1,r);
    int between = merge(l,mid,r);
    return left+right+between;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("%d",mergesort(0,n-1));
}