#include<stdio.h>
#include<string.h>
#include<math.h>
void simpleSieve(int limit, int prime[]) 
{ 
	int mark[limit + 1]; 
	memset(mark, 0, sizeof(mark)); 

	for (int i = 2; i <= limit; ++i) { 
		if (!mark[i]) { 
			// If not marked yet, then its a prime 
			prime[i]++; 
			for (int j = 2*i; j <= limit; j += i) //getting all prime numbers between 0 and root(high)
				mark[j] = 1; 
		} 
	} 
}
void primesInRange(int low, int high) 
{
	int limit = floor(sqrt(high)) + 1; 
	int prime[limit+1];
	memset(prime, 0, sizeof(prime)); 
	simpleSieve(limit, prime); 

	int n = high - low + 1; 

	// Declaring boolean only for [low, high] 
	int mark[n + 1]; 
	memset(mark, 0, sizeof(mark)); 

	// Use the found primes by simpleSieve() to find 
	// primes in given range 
	for (int i = 0; i < limit+1; i++) { 
		// Find the minimum number in [low..high] that is 
		// a multiple of prime[i] (divisible by prime[i]) 
		if(prime[i]){
			int loLim = floor(low / prime[i]) * prime[i]; 
			if (loLim < low) 
				loLim += prime[i]; 
			if(loLim==prime[i]) 
				loLim += prime[i]; 
			for (int j = loLim; j <= high; j += prime[i]) 
				mark[j - low] = 1;
		}
	}
	int freq[10] = {0};
	for (int i = low; i <= high; i++) {
		if (!mark[i - low]) {
			printf("%d ", i);
			int copy = i-low;
			freq[copy%10]++;
			copy /= 10;
		}
	}
	int max = 0, ans;
	for (int i = 0; i <= 9; i++){
		if(freq[i] > max){
			max = freq[i];
			ans = i;
		}
	}
	printf("%d %d\n", ans, max);
} 
int main() 
{ 
	int a,b;
	scanf("%d %d", &a, &b);
	primesInRange(a, b);

	return 0; 
}