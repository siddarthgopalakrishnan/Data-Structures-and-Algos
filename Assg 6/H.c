#include<stdio.h>
int arr[3000000];
int stack[3000000];
int top=-1;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int i=0,ind,max1=-1,ans;
    while(i<n)
    {
        if(top==-1||arr[i]>=arr[stack[top]])
        {
            stack[++top]=i;i++;
        }
        else if(arr[i]<arr[stack[top]])
        {
            ind = stack[top];
            top--;
            ans = arr[ind]*(top==-1?i:i-stack[top]-1);
            if(ans>max1)
                max1=ans;
        }
    }
    while(top!=-1)
    {
        ind = stack[top];
        top--;
        ans = arr[ind]*(top==-1?i:i-stack[top]-1);
        if(ans>max1)
            max1=ans;
    }
    printf("%d\n",max1);
}