#include<stdio.h>
#include<string.h>
char num[100000];
int num1[100000],num2[100000],ans[100000];
int l[1000],r[10000],mm[20000];
int borrow=0;
void merge(int * arr,int left,int mid,int right)
{
    for(int i=0;i<=mid-left;i++)
    {
        l[i]=arr[left+i];
    }
    for(int i=mid+1;i<=right;i++)
    {
        r[i-mid-1]=arr[i];
    }
    int i=0,j=0,k=0;
    while(i<=mid-left&&j<=(right-mid-1))
    {
        if(l[i]<r[j])
            mm[k++]=l[i++];
        else
            mm[k++]=r[j++];
    }
    while(i<=mid-left)
        mm[k++]=l[i++];
    while(j<=right-mid-1)
        mm[k++]=r[j++];
    for(int i=0;i<k;i++)
    {
        arr[left+i]=mm[i];
    }
}
void mergesort(int *arr,int left,int right)
{
    if(left==right)
        return;
    else
    {
        int mid=left +(right-left)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
void subtract(int * arr1,int *arr2,int len)
{
    int a,b,c;
    for(int i=len-1;i>=0;i--)
    {
        a=arr1[i];
        b=arr2[i];
        c=borrow;
        ans[i]=(a+10-b-c)%10;
        if(a-b-c>=0)
            borrow=0;
        else
            borrow=1;

    }
}
int main()
{
    scanf("%s",num);
    int len = strlen(num);
    for(int i=0;i<len;i++)
    {
        num2[i]=num[i]-'0';
    }
    mergesort(num2,0,len-1);
    for(int i=0;i<len;i++)
    {
        num1[i]=num2[len-i-1];
    }
    for(int i=0;i<len;i++)
    {
        if(num2[i]!=0)
        {
            int a=num2[i];
            int b=num2[0];
            num2[0]=a;
            num2[i]=b;
            break;
        }
    }
    subtract(num1,num2,len);
    for(int i=0;i<len;i++)
    {
        printf("%d",ans[i]);
    }
}
