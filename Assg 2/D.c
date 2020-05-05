#include<stdio.h>

int main()
{
	
	int n,m;
	scanf("%d %d",&n,&m);
	
	int arr[n][n];
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		
		arr[a-1][b-1]=arr[b-1][a-1]=1;
		
	}
	
	int visited[n];
	
	for (int i=0;i<n;i++)
	{
		visited[i]=0;
	}
	int k=0;
	for(int i=0;i<n;i++)
	{
		/*printf("%d",visited[i]);
		if(visited[i]==0)
		visited[i]=++k;
		printf(" %d\n",visited[i]);
		*/
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]==1 || arr[j][i] == 1)
			{
				if(visited[i]==0 && visited[j] ==0)
					visited[i]=++k;
				else if( visited[i] == 0)
					visited[i] = visited[j];
				else if(visited[j]==0)
					visited[j]=visited[i];
						
				else	
				visited[j]=visited[i];
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",visited[i] );
		}
		printf("\n");
	
	int maxarr[n];
	int r;
	for(int i=0;i<n;i++)
		maxarr[i]=0;
		
	for(int i=0;i<n;i++)
	{
		maxarr[visited[i]]++;
	}
	
	int max=0,count =0;
	for(int i=0;i<n;i++)
	{
		if(maxarr[i] != 0)
		{
			//count++;
			if(maxarr[i] >max)
			{
				max= maxarr[i];
				r=i;
			}
		}
	}
	
	
	for(int i=0;i<n;i++)
	{
		if((visited[i])!= r)
		{
			printf("%d ",i+1);
			count++;
		}
	}
	printf("\n");
	
	printf("%d",count);
	
	return 0;
}