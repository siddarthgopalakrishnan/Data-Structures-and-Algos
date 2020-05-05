#include<stdio.h>
int matrix[500][500];
int vis[500][500];
int moves[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int n,m,p1,q1,p2,q2;
int dfs(int x,int y)
{
    if(x==p2&&y==q2)
        return 1;
    vis[x][y]=1;
    int newx,newy;
    for(int i=0;i<4;i++)
    {
        newx = x+moves[i][0];
        newy = y+moves[i][1];
        if(newx>=0&&newx<n&&newy>=0&&newy<n)
        {
            if(matrix[newx][newy]==1&&vis[newx][newy]==0)
            {
                if(dfs(newx,newy))
                    return 1;
            }
        }
    }
    vis[x][y]=0;
    return 0;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&matrix[i][j]);

    scanf("%d%d",&p1,&q1);
    scanf("%d%d",&p2,&q2);
    if(dfs(p1,q1))
        printf("YES\n");
    else
        printf("NO\n");
}