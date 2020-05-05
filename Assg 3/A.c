#include<stdio.h>
#include<math.h>
#include<limits.h>
int max = INT_MIN;
int arr[100000];
int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	for(int i=0; i<n; i++){
		int count=0;
		for(int j=0; j<n; j++){
			if(arr[j] == arr[i])
				count++;
		}
		if(count >= ceil((float)n/2)){
			if(arr[i] > max)
				max = arr[i];
		}
	}
	if(max != INT_MIN){
		printf("%d\n", max);
	}
	else printf("NO MAJORITY ELEMENT");
}