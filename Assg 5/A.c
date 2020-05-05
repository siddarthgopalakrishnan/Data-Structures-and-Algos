#include <stdio.h>
#include <string.h>

int max = -1 ;
int pos1 = -1 ;
int pos2 = -1 ;

void dfs(int ele, int n, int adjmat[][n], int visited[], int dist, int start)
{
    visited[ele] = 1;
    if(dist > max)
    {
        max = dist ;
        pos1 = start ;
        pos2 = ele ;
    }
    else if(dist == max)
    {
        if(start < pos1)
        {
            max = dist ;
            pos1 = start ;
            pos2 = ele ;
        }
        else if(start == pos1 && ele > pos2)
        {
            max = dist ;
            pos1 = start ;
            pos2 = ele ;
        }
    }

    for(int i=0; i<n; i++)
    {
        if(!visited[i] && adjmat[ele][i])
        {
            dfs(i, n, adjmat, visited, ++dist, start) ;
            dist-- ;
        }    
    }
}

int main()
{
    int n ;
    scanf("%d", &n) ;
    int adjmat[n][n] ;
    memset(adjmat, 0 ,sizeof(adjmat)) ;

    for(int i=0; i<n-1; i++)
    {
        int u, v ;
        scanf("%d %d", &u, &v) ;
        adjmat[u][v] = 1 ;
        adjmat[v][u] = 1 ;
    }

    int visited[n] ;
    for(int i=0; i<n; i++)
    {
        memset(visited, 0, sizeof(visited)) ;
        int start = i ;
        dfs(i, n, adjmat, visited, 0, start) ;
    }
    printf("%d\n%d %d\n", max, pos1, pos2) ;
}