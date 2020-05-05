#include<stdio.h>
#define lli long long int
int main(){
	int q; scanf("%d", &q);
	while(q--){
		lli x; scanf("%lld", &x);
		lli i = 1;
		while(i*i <= x)
			i *= 2;
		i /= 2;
		while(i*i <= x)
			i++;
		printf("%lld\n", i-1);
	}
}