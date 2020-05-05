#include <stdio.h>
int n;
int length = 1, ans = 1;
int getPath(unsigned int curr){
 	int count = 1;
  	while(curr != 1){
		if(curr%2 == 0) curr /= 2;
		else curr = curr*3 + 1;
		count++;
	}
 	return count;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int len = getPath(i);
	    if(len > length){
	    	length = len;
	      	ans = i;
	    }
	}
	printf("%d %d\n", ans, length);
}