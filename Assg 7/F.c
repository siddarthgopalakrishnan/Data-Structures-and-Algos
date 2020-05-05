#include<stdio.h>

int main(){
	int n,x, max = 0;
	int height[5001] = {};
	scanf("%d",&n);
	char ch = '\0';
	for (int i = 0; i < n; i++){
		while(ch != '\n'){
			scanf("%d%c",&x,&ch);
			if (x > i){
				height[x] = height[i]+1;
				max++;
			}
		}
		ch = '\0';
	}
	for (int j = 0; j <= max; j++){
		for (int i = 0; i < n; i++)
			if (height[i] == j)
				printf("%d ", i);
		printf("\n");
	}
}