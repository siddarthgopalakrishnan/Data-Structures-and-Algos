#include<stdio.h>
int n, s, e;
int times[100000][2];
void swap(int* x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
void insertion(int i){
	while(i>0&&times[i][1]<times[i-1][1]){
		swap(&times[i][1], &times[i-1][1]);
		swap(&times[i][0], &times[i-1][0]);
		i--;
	}
}
int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d %d", &times[i][0], &times[i][1]);
		insertion(i);
	}
	int count = 1;
	int i=0;
	for(int j=1; j<n; j++){
		if(times[j][0] > times[i][1]){
			count++;
			i=j;
		}
	}
	printf("%d\n", count);
	return 0;
}