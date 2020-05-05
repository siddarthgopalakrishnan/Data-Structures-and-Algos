#include<stdio.h>
int adj[1000][1000];
int vis[1000],cnt,grp=1;
int n,m,u,v,x,removed;
void dfs(int curr)
{
    vis[curr]=grp;
    cnt++;
    for(int i=0;i<n;i++)
    {
        if(adj[curr][i]==1&&i!=removed&&vis[i]!=grp)
        {
            dfs(i);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&u,&v);
        adj[u][v]=1;
        adj[v][u]=1;
    }
    scanf("%d",&x);
    int min = 10001;
    int ans,flag=0;
    for(int i=0;i<n;i++)
    {
        if(i!=x)
        {
            removed = i;
            cnt = 0;
            dfs(x);
            if(cnt<n-1)
            {
                flag=1;
                if(min>cnt)
                {
                    min=cnt;
                    ans=i;
                }
            }
            grp++;
        }
    }
    if(flag==0)
        printf("BLACK OUT\n");
    else
        printf("%d\n",ans);
}