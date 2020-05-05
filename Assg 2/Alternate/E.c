#include<stdio.h>
int adj[500][500];
int vis[500];
int freq[500];
int cnt;
int n,m,u,v;
void dfs(int curr)
{
    vis[curr]=1;
    cnt++;
    for(int i=1;i<=n;i++)
    {
        if(adj[curr][i]==1&&vis[i]==0)
        {
            dfs(i);
        }
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&u,&v);
        adj[u][v]=1;
    }
    for(int i=1;i<=n;i++)
    {
        dfs(i);
        if(cnt==n)
        {
            printf("%d ",i);
        }
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            vis[i]=0;
        }
    }

}