#include<stdio.h>
#include<string.h>
int vis[1000000];
int q[1000000];
int parent[1000000];
int main()
{
    int a[3],b[3],x=0,start=0,end=0;
    memset(parent,-1,1000000*sizeof(parent[0]));
    for(int i=0;i<3;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
    }
    int nex;
    int q1;
    scanf("%d",&q1);
    while(q1--)
    {
        int y;
        scanf("%d",&y);
        x=0;
        q[0]=0;
        int flag=1;
        vis[0]=1;
        if(vis[y]==0)
        {
            flag=0;
            while(end<1000000&&end>=start)
            {
                x=q[start];
                if(x==y)
                {
                    flag=1;
                    break;
                }
                for(int i=0;i<3;i++)
                {
                    nex = a[i]*x+b[i];
                    if(nex<1000000&&vis[nex]==0)
                    {
                        vis[nex]=1;
                        parent[nex]=x;
                        q[++end]=nex;
                    }
                }
                start++;
            }
        }
        if(flag == 0)
        {
            printf("-1\n");
        }
        else
        {
            int k = y;
            int cnt = 0;
            while(k!=0)
            {
                k = parent[k];
                cnt++;
            }
            printf("%d\n",cnt);
        }
    }
}
