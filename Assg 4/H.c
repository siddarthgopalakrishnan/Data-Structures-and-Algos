#include<stdio.h>
#define int long long int
int n,m;
int l,r,x;
int arr[1000000];
int main(){
	scanf("%lld %lld", &n, &m);
	while(m--){
		scanf("%lld %lld %lld", &l, &r, &x);
		for(int i=l; i<=r; i++){
			arr[i] = arr[i] + x;
		}
	}
	for(int i=0; i<n; i++){
		printf("%lld ", arr[i]);
	}
	printf("\n");
}