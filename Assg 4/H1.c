#include<stdio.h>
#include<string.h>

int main(){
	int n,m;
	scanf("%d %d", &n, &m);
	int l,r,x;
	long long amt[n];
	memset(amt, 0, sizeof(long long)*n);
	for(int i=0; i<m; i++){
		scanf("%d %d %d", &l, &r, &x);
		amt[l] += x;
		amt[r+1] -= x;
	}
	for(int i=1; i<n; i++)
		amt[i] += amt[i-1];
	for(int i=0; i<n; i++)
		printf("%d ", amt[i]);
	printf("\n");
}