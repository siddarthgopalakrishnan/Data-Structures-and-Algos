#include<stdio.h>
#include<string.h>
int n,p[5000][3],top=-1,topofarr=0,maxp=-1;
int stack[5000][3];
int ans[10000];
void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void insertion(int i)
{
    while(i>0&&p[i][1]<=p[i-1][1])
    {
        if(p[i][1]==p[i-1][1])
        {
            if(i>0&&p[i][0]>p[i-1][0])
            {
                swap(&p[i][0],&p[i-1][0]);
                swap(&p[i][1],&p[i-1][1]);
                swap(&p[i][2],&p[i-1][2]);
            }
            i--;
        }
        else 
        {
            swap(&p[i][0],&p[i-1][0]);
            swap(&p[i][1],&p[i-1][1]);
            swap(&p[i][2],&p[i-1][2]);
            i--;
        }
       
    }
}
void push(int x,int y,int t)
{
    stack[++top][0]=x;
    stack[top][1]=y;
    stack[top][2]=t;
}
void pop()
{
    if(top!=-1) top--;
}
int topstack(int *x,int *y,int * t )
{
    if(top!=-1)
    {
        *x = stack[top][0];
        *y = stack[top][1];
        *t = stack[top][2];
        return 1;
    }
    return 0;
}
void pushall(int currtime)
{
    while(topofarr<n&&currtime>=p[topofarr][1])
    {
        push(p[topofarr][0],p[topofarr][1],p[topofarr][2]);
        topofarr++;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&p[i][j]);
        }
        if(maxp<p[i][0])
            maxp = p[i][0];
        insertion(i);
    }
    int currtime=0;
    int currp,currs,currt,timep=0;
    while(topofarr!=n)
    {
        pushall(currtime);
        if(topstack(&currp,&currs,&currt)==0)
        {
            currtime = p[topofarr][1];
            pushall(currtime);
            topstack(&currp,&currs,&currt);
        }
        timep = p[topofarr][1] - currtime;
        if(timep<0)continue;
        if(timep>=currt)
        {
            pop();
            currtime +=currt;
            ans[currp] = currtime;
        }
        else
        {
            currt -= timep;
            pop();
            push(currp,currs,currt);
            currtime += timep;
        }
    }
    while(top!=-1)
    {
        topstack(&currp,&currs,&currt);
        pop();
        currtime +=currt;
        ans[currp] = currtime;
    }
    for(int i=0;i<=maxp;i++)
    {
        if(ans[i]!=0){printf("%d %d\n",i,ans[i]);break;}
    }
}