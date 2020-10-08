#include<stdio.h>
int n;
unsigned long long arr[1000002];

void precompute()
{
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	for(int i=3; i<=1000001; i++)
	{
		arr[i] = arr[i-1]+arr[i-2];
	}
}

int main() {
	scanf("%d", &n);
	precompute();
	printf("%llu\n", arr[n]);
}