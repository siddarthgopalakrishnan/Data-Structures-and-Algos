#include<stdio.h>
int main()
{
	char str[1000000],f[100]={0};
	char words[100][100];
	int i=0,length=0;
	scanf("%[^\n]",str);
	//printf("%s",str);
	for(i=0;str[i]!='\0';i++);
	length=i;
	int flag=0,k=0,l=0,temp=0;
	for(i=0;i<length;i++)
	{
		if(str[i]==' ')
		{
			//printf("YES\n");
			temp=i-flag;
			for(l=0;l<temp;l++,flag++)
			{
				words[k][l]=str[flag];
			}
			f[k]=temp;
			flag++;
			k++;
		}
	}
	temp=i-flag;
	for(l=0;l<temp;l++,flag++)
	{
		words[k][l]=str[flag];
	}
	f[k]=temp;
	flag++;
	k++;
	//for(i=0;i<k;i++)
	//	printf("%d ",f[i]);
	int j=0;
	for(i=0;i<k;i++)
	{
		
		for(j=f[i]-1;j>=0;j--)
			printf("%c",words[i][j]);
		printf(" ");
	}
	printf("\n");
	temp=1;
	for(i=0;i<k;i++)
	{
		//printf("Check %d \n",f[i]);
		
		for(j=0;j<f[i]/2;j++)
		{
			//printf("%c %c\n",words[i][j],words[i][f[i]-j-1]);
			if(words[i][j]!=words[i][f[i]-j-1])
			{
				//printf("No");
				temp=0;
				break;
			}
		}
		if(temp==1)
		{
			for(j=0;j<f[i];j++)
				printf("%c",words[i][j]);
			printf("\n");
		}
		temp=1;
		
	}
	return 0;
}