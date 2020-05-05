#include<stdio.h>
#include<string.h>
int main()
{
	char str[1000];
	scanf("%s",str);
	int l= strlen(str);
	char word[l];
	scanf("%s",word);
	int len= strlen(word);
	int ans=0;
	
	if(len ==1)
	{
		for(int i=0;i<l;i++)
		{
			if(str[i]==word[0])
			ans++;
		}
	}
	else
	{
		for(int i=0;i<l-len+1;i++)
		{
			int count=0;
			for(int j=i;j<len+i;j++)
			{
				if(str[j]==word[j-i])
				{
					count++;
				}
			}
			if(count == len || count == len-1)
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}