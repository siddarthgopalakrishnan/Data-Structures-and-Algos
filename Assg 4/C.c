#include<stdio.h>
#include<string.h>
char str[100000][51];
int n;

int isSmall(char *str1, char *str2){
	int len1 = strlen(str1); int len2 = strlen(str2);
	if(str1[0] == '-' && str2[0] != '-') return 1;
	if(str1[0] != '-' && str2[0] == '-') return 0;
	if(str1[0] != '-' && str2[0] != '-'){
		if(len1>len2) return 0;
		if(len2>len1) return 1;
		if(strcmp(str1, str2)>0) return 0;
		else return 1;
	}
	else{
		if(len1>len2) return 1;
		if(len2>len1) return 0;
		if(strcmp(str1, str2)>0) return 1;
		else return 0;
	}
}

void sort(){
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(isSmall(str[i], str[j])){
				char temp[51];
				strcpy(temp, str[i]);
				strcpy(str[i], str[j]);
				strcpy(str[j], temp);
			}
		}
	}
}
int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%s", str[i]);
	}
	sort();
	for(int i=0; i<n; i++){
		printf("%s\n", str[i]);
	}
}