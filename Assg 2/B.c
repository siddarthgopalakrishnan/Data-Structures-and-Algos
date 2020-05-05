#include<stdio.h>
#include<string.h>

int a,b,c,d,e,f;

int min(int a, int b){
	return (a<b)?a:b;
}

int find(int n){
	if (n < 0)
		return 1e9;
	if (n == 0)
		return 0;
	int x = 1e9;
	if ((n-b)%a == 0)
		x = min(x, find((n-b)/a)+1);
	if ((n-d)%c == 0)
		x = min(x, find((n-d)/c)+1);
	if ((n-f)%e == 0)
		x = min(x, find((n-f)/e)+1);
	return x;
}
int main() {
	int q, x;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d", &x);
		x = find(x);
		if (x == 1e9)
			x = -1;
		printf("%d\n", x);
	}
}