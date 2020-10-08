#include<stdio.h>
#include<string.h>

int arr[26];
char ans[26];
int main() {
	char ch; int k=0;
	while(scanf("%c", &ch)){
		if(ch=='\n') break;
		arr[ch-'a'] = 1;
	}
	for(int i=0; i<26; i++)
	{
		if(arr[i] && !arr[26-1-i])
		{
			ans[k++] = (char)(i + 97);
		}
	}
	if(!k) printf("YES\n");
	else
	{
		printf("NO\n");
		for(int i=0; i<k; i++)
		{
			printf("%c ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}