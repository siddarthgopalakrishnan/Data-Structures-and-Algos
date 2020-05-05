#include<stdio.h> 
#include<string.h>
#define lli long long int
void sieve(lli prime[], lli n) 
{ 
	for (lli p = 2; p * p <= n; p++) 
	{ 
		if (!prime[p]) 
			for (lli i = p*2; i <= n; i+=p) 
				prime[i] = 1; 
	} 
}

int main() 
{ 
	lli L,R;
	scanf("%lld %lld", &L, &R);
	lli prime[R+1]; 
	memset(prime, 0, sizeof(prime));
	sieve(prime, R); 
	lli freq[10] = {0};
	lli val;
	
	for (lli i = L; i <= R; i++) 
	{ 
		if (!prime[i]) 
		{ 
			lli p = i; // If i is prime 
			while (p) 
			{ 
				freq[p%10]++; 
				p /= 10; 
			} 
		} 
	}
	lli max = freq[0], ans = 0; 
	for (lli j = 1; j < 10; j++) 
	{ 
		//printf("%lld ", freq[j]);
		if (max <= freq[j]) 
		{ 
			max = freq[j]; 
			ans = j; 
		} 
	}
	printf("%lld %lld\n", ans, max);
	return 0; 
} 
