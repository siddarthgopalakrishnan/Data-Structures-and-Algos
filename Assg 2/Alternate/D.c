#include<stdio.h>
int adj[500][500];
int vis[500];
int freq[500];
int grp =0;
int n,m,u,v;
void dfs(int curr)
{
    vis[curr]=grp;
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
        adj[v][u]=1;
        adj[u][v]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            grp++;
            dfs(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        freq[vis[i]]++;
    }
    int max =0;
    for(int i=1;i<=grp;i++)
    {
        if(freq[i]>freq[max])
            max=i;
    }
    printf("%d\n",n-freq[max]);
    for(int i=1;i<=n;i++)
    {
        if(vis[i]!=max)
        {
            printf("%d ",i);
        }
    }

}
