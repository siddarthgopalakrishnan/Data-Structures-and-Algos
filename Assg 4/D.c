#include<stdio.h>
int stop[100000];
void swap(int *x,int *y)
{
    int temp = *x;
    *x =*y;
    *y = temp;
}
void insertion(int i)
{
    while(i>0&&stop[i]<stop[i-1])
    {
        swap(&stop[i],&stop[i-1]);
        i--;
    }
}
int main()
{
    int n,m,q,k,left,right,flag,mid;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d",&stop[i]);
        insertion(i);
    }
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&k);
        left =0;
        right=m-1;
        flag=0;
        while(left<right)
        {
            mid = (left+right)/2;
            if(stop[mid]==k){
                printf("0\n");
                flag=1;
                break;
            }
            else if(stop[mid]>k){
                right = mid-1;
            }
            else{
                left=mid+1;
            }
        }
        if(flag==0)
        {
            if(left!=m-1&&k-stop[left]>stop[left+1]-k)
                printf("%d\n",stop[left+1]-k);
            else
                printf("%d\n",k-stop[left]);
        }
    }
}