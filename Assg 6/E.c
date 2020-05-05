#include<stdio.h>
#include<string.h>
int moves[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
char inp[500][500];
int vis[500][500];
char word[250000];
int grp;
int stack[500][4];
int top=-1;
int n,m,len;
void push(int x,int y,int i)
{
    stack[++top][0]=x;
    stack[top][1]=y;
    stack[top][2]=i;
}
void pop()
{
    if(top!=-1) top--;
}
int top1(int *a,int *b,int *c)
{
    if(top!=-1)
    {
        *a = stack[top][0];
        *b = stack[top][1];
        *c = stack[top][2];
        return 1;
    }
    return 0;
}
int dfs(int x,int y,int i)
{
    push(x,y,i);
    int currx,curry,curri=0,newx,newy;
    while(top!=-1&&curri<=len-1)
    {
        top1(&currx,&curry,&curri);
        printf("%d %d %d\n",currx,curry,curri);
        if(vis[currx][curry]==grp&&inp[currx][curry]==word[curri])
        {
        	vis[currx][curry]=0;
        	pop();
        }
        else
        {
	        vis[currx][curry]=grp;
	        if(inp[currx][curry]==word[curri])
	        {
	            if(curri==len-1)break;
	            for(int i=0;i<4;i++)
	            {
	                newx = currx + moves[i][0];
	                newy = curry + moves[i][1];
	                if(newx>=0&&newx<n&&newy>=0&&newy<m)
	                    if(vis[newx][newy]!=grp)
	                        push(newx,newy,curri+1);
	            }
	        }
	        else
	        {
	            vis[currx][curry]=0;
	            pop();
	        }
        }
    }
    if(curri==len-1) return 1;
    else return 0;
    push(x,y,i);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf(" %s",inp[i]);

    int q;
    scanf("%d",&q);
    while(q--)
    {
        scanf(" %s",word);
        len = strlen(word);
        int flag=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(word[0]==inp[i][j])
                {
                    grp++;
                    if(dfs(i,j,0))
                    {
                        printf("%d %d\n",i,j);
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==1) break;
        }
        if(flag==0) printf("-1\n");
    }
}