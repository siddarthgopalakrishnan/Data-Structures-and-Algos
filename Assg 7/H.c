#include<stdio.h>
int n;
int arr[100000][2];
void swap(int *x, int *y){
	int temp = *x; *x = *y; *y = temp;
}

void insertion(int i){
	while(i>0 && arr[i][0]<arr[i-1][0]){
		swap(&arr[i][0], &arr[i-1][0]);
		swap(&arr[i][1], &arr[i-1][1]);
		i--;
	}
}

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i][0]);
		arr[i][1] = i;
		insertion(i);
	}
	int vis[n];
	for(int i =0; i<n; i++) vis[i] = 0;
	int ans=0;
	for(int i = 0; i<n; i++){
		if(vis[i] || arr[i][1] == i)
			continue;
		int cycle=0; int j=i;
		while(!vis[j]){
			vis[j] = 1;
			j = arr[j][1];
			cycle++;
		}
		if(cycle>0) ans += (cycle-1);
	}
	printf("%d\n", ans);
}