#include <stdio.h>
#include <string.h>

int stack[1000] ;
int top = -1 ;
int flag = 0 ;

void dfs(int ele, int n, int adjmat[][n], int visited[], int start)
{
    visited[ele] = 1 ;
    if(adjmat[ele][start] == 1)
        flag++ ;

    for(int i=0; i<n; i++)
    {
        if(!visited[i] && adjmat[ele][i])
            dfs(i, n, adjmat, visited, start) ;
    }
    top++ ;
    stack[top] = ele ;
}

int main()
{
    int n, m ;
    scanf("%d %d", &n, &m) ;

    int visited[n] ;
    int adjmat[n][n] ;
    memset(visited, 0, sizeof(visited)) ;
    memset(adjmat, 0, sizeof(adjmat)) ;
    memset(stack, -1, sizeof(stack)) ;

    for(int i=0; i<m; i++)
    {
        int u, v ;
        scanf("%d %d", &u, &v) ;
        adjmat[v-1][u-1] = 1 ;
    }

    for(int i=0; i<n; i++)
    {
        if(!visited[i])
            dfs(i, n, adjmat, visited, i) ;
    }
    if(flag != 0)
    {
        printf("NOT POSSIBLE") ;
        return 0 ;
    }
    for(int i=n-1; i>=0; i--)
        printf("%d ", stack[i]+1) ;
}