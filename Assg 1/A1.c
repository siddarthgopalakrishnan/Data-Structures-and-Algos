#include<stdio.h>

int main()
{
	int n,m,x,y;
	scanf("%d %d", &n, &m);
	int p[n][m];
	//Accepting first matrix
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			scanf(" %d", &p[i][j]);
		}
	}
	scanf("%d %d", &x, &y);
	int q[x][y];
	//Accepting second matrix
	for(int i=0; i<x; i++)
	{
		for(int j=0; j<y; j++)
		{
			scanf(" %d", &q[i][j]);
		}
	}
	//Run loops and check
	int i,j,k,l, flag=0;
	for(i=0; i<n-x+1; i++)// +1 -> less than n-x.
	{
		for(j=0; j<m-y+1; j++)
		{
			int count=0;
			if(p[i][j] == q[0][0])
			{
				for(k=0; k<x; k++)
				{
					for(l=0; l<y; l++)
					{
						if(p[i+k][j+l] == q[k][l])
						{
							count++;
						}
					}
				}	
			}
			if(count == (x*y))
			{
				flag=1;
				printf("YES\n%d %d\n", i, j);
				return 1;
			}
		}
	}
	if(!flag)
	{
		printf("NO\n");
	}
	return 0;
}