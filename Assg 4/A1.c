#include<stdio.h>
#include<limits.h>
#include<math.h>
float getSlope(int pos[][3],int i,int x0,int y0)
{
	return x0==pos[i][1]?INT_MAX:(float)(y0-pos[i][2])/(x0-pos[i][1]);
}
void swap(float slopes[],int pos[][3],int j)
{
	int t; float f;
	f=slopes[j+1]; slopes[j+1]=slopes[j]; slopes[j]=f;
	t=pos[j+1][0]; pos[j+1][0]=pos[j][0]; pos[j][0]=t;
	t=pos[j+1][1]; pos[j+1][1]=pos[j][1]; pos[j][1]=t;
	t=pos[j+1][2]; pos[j+1][2]=pos[j][2]; pos[j][2]=t;
}
int main()
{
	int n,i,j=0,small=INT_MAX,ind,x0,y0;
	scanf("%d",&n);
	int pos[n][3]; float slopes[n];
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&pos[i][0],&pos[i][1],&pos[i][2]);
		if(small>pos[i][2])
		{
			small=pos[i][2];
			ind=pos[i][0]; x0=pos[i][1]; y0=pos[i][2];
		}
	}
	for(i=0;i<n;i++)
		slopes[j++]=getSlope(pos,i,x0,y0);
	for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++)
		{
			if(slopes[j]>slopes[j+1])
				swap(slopes,pos,j);
			if(slopes[j]==slopes[j+1] && (abs(pos[j][1]-x0)+abs(pos[j][2]-y0)) > (abs(pos[j+1][1]-x0)+abs(pos[j+1][2]-y0)))
				swap(slopes,pos,j);
		}
	for(i=0;i<n;i++)
		if(ind!=pos[i][0] && slopes[i]>=0)
			printf("%d ",pos[i][0]);
	for(i=0;i<n;i++)
		if(ind!=pos[i][0] && slopes[i]<0)
			printf("%d ",pos[i][0]);
}