#include<stdio.h>
int parent[1000];
int adj[1000][1000];
int q[1000][2],ans[1000];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d",&parent[i]);
        adj[parent[i]][i]=1;
    }
    int k;
    scanf("%d",&k);
    int first=0,last=1;
    q[first][0]=0;
    q[first][1]=0;
    int curr,it;
    while(first<last)
    {
        curr = q[first][0];
        for(int i=0;i<n;i++)
        {
            if(adj[curr][i]==1)
            {
                q[last][0]=i;
                q[last++][1]=q[first][1]+1;
            }
        }
        first++;
    }
    int cnt=0;
    for(int i=0;i<last;i++)
    {
        //printf("%d %d\n",q[i][0],q[i][1]);
        if(q[i][1]==k)
        {
            cnt++;
            ans[q[i][0]]++;
        }
    }
    if(cnt==0)
        printf("-1\n");
    else
    {
        printf("%d\n",cnt);
        for(int i=0;i<n;i++)
        {
            if(ans[i]==1)
                printf("%d ",i);
        }
    }
}
