#include<stdio.h>
int adj[5000][5000],vis[5000],ans[5000];
int n,u,v,w[5000][5000],p,z,k,degree[5000];
int dog[5000];
int stack[5000];
void swap(int *a,int *b)
{
    int temp = *a;
    *a =*b;
    *b = temp;
}
void insertion(int i)
{
    while(ans[i]<ans[i-1])
    {swap(&ans[i],&ans[i-1]);i--;}
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        scanf("%d %d %d",&u,&v,&z);
        adj[u][v]=1;
        adj[v][u]=1;
        w[u][v]=z;
        w[v][u]=z;
        degree[u]++;
        degree[v]++;
    }
    scanf("%d %d",&p,&k);
    z=-1;
    int curr = p;
    stack[++z]=curr;
    int t=0;
    while(z!=-1)
    {
        curr=stack[z];
        vis[curr]=1;
        if(degree[curr]==1&&dog[curr]<k)
        {
            ans[t++]=curr;
            insertion(t-1);
        }
        z--;
        for(int i=0;i<n;i++)
        {
            if(adj[curr][i]==1&&vis[i]!=1)
            {
                stack[z+1]=i;
                dog[i] = dog[curr]+w[curr][i];
                z++;
            }
        }
    }
    for(int i=0;i<t;i++)
        printf("%d ",ans[i]);
    printf("\n");
}