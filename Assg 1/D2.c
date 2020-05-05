#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000000];
	scanf("%[^\n]%*c", s);
	char hash_sub[128];
	memset(hash_sub, 0, sizeof(hash_sub));
	int end, max=0, pos1=0, pos2=0, size=0;
	while(pos2<strlen(s)){
		if(hash_sub[s[pos2]] == 0){
			hash_sub[s[pos2]]++;
			pos2++;
			size++;
			if(max<size){
				end = pos2-1;
				max = size;
			}
		}
		else if(hash_sub[s[pos2]] != 0){
			size--;
			hash_sub[s[pos1]]--;
			pos1++;
		}
	}
	printf("%d\n", max);
	for(size = end-max+1; size<=end; size++)
		printf("%c", s[size]);
	printf("\n");
}