#include <stdio.h>
#define MAX 100
#define M 100
#define N 100
int mat[M][N], visited[M][N];
int min_dist = MAX;

int isSafe(int x, int y)
{
	if (mat[x][y] == 0 || visited[x][y])
		return 0;
	return 1;
}

int isValid(int x, int y)
{
	if (x < M && y < N && x >= 0 && y >= 0)
		return 1;
	return 0;
}

void findShortestPath(int i, int j, int x, int y,int dist)
{
	if (i == x && j == y) 
	{
		if(dist<min_dist)
			min_dist = dist;
		return;
	}
	visited[i][j] = 1;
	if (isValid(i + 1, j) && isSafe(i + 1, j))
		findShortestPath(i + 1, j, x, y, dist + 1);
	if (isValid(i, j + 1) && isSafe( i, j + 1))
		findShortestPath(i, j + 1, x, y, dist + 1);
	if (isValid(i - 1, j) && isSafe(i - 1, j))
		findShortestPath(i - 1, j, x, y, dist + 1);
	if (isValid(i, j - 1) && isSafe( i, j - 1))
		findShortestPath(i, j - 1, x, y, dist + 1);
	visited[i][j] = 0;
}

int main()
{
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	for(i = 0;i<n;i++)
		for(j = 0;j<m;j++)
			scanf("%d",&mat[i][j]);
	
	int from_x,from_y,to_x,to_y;
	scanf("%d %d",&from_x,&from_y);
	scanf("%d %d",&to_x,&to_y);

	for(i = 0;i<n;i++){
		for(j = 0;j<m;j++){
			visited[i][j] = 0;
		}
	}
		
	findShortestPath(from_x, from_y, to_x, to_y, 0);
 
	if(min_dist != MAX)
		printf("YES");
	else 
		printf("NO");
	
	return 0;
}