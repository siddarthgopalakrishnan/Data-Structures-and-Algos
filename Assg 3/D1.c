#include<stdio.h>
#include<string.h>

void cal(char s[100],char w[100]){
	int i=0,j=0,flag = 0,count = 0;
	int len1 = strlen(s);
	int len2 = strlen(w);
	while(i<len1){			
		if(s[i]==w[j]){			//char match
			i++;
			j++;
			if(j==len2){		//w is done checking
				count++;
				j = 0;
				flag = 0;
			}
		}else{					//char dont match
			if(flag==0){		//first occurence of mismatch ignored
				flag = 1;
				i++;
				j++;
				if(j==len2){
					i--;
					count++;
					j = 0;
					flag = 0;
				}
			}else if(flag==1){	//2nd mismatch considered wrong
				flag = 0;
				j = 0;
			}
		}
	}
	printf("ANS  = %d",count);
	return;
}
int main(){
	char s[100],w[100];
	scanf("%s",s);
	scanf("%s",w);
	cal(s,w);
	return 0;
}
