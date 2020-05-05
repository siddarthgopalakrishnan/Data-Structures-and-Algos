#include<stdio.h>
int adj[10000][10000];
int n,grp=0;
int  vis[100000],degree[100000],ans[100000];
int dfs(int curr)
{
    if(curr==0)
        return 0;
    vis[curr]=grp;
    for(int i=0;i<n;i++)
    {
        if(adj[curr][i]==1&&vis[i]!=grp)
        {
            return 1 + dfs(i);
        }
    }
}
int main()
{
    int u,v;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        scanf("%d %d",&u,&v);
        adj[u][v]=1;
        adj[v][u]=1;
        degree[u]++;
        degree[v]++;
    }
    int min = 100000,index=0;
    for(int i=0;i<n;i++)
    {
        if(degree[i]==1)
        {
            grp=i;
            ans[i] = dfs(i);
            if(ans[i]<min)
            {
                min = ans[i];
            }
        }
    }
    int cnt=0;
    for(int i=n-1;i>=0;i--)
    {
        if(ans[i]==min)
        {
            cnt++;
            index=i;
        }
    }
    printf("%d\n%d",cnt,index);
}