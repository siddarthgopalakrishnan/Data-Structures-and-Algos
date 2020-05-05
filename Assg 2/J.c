#include<stdio.h>
#include<math.h>
#define lli long long int
lli getXors(lli n){
	lli ans = 0;
	if (n % 2 == 0) {
        ans = ans^2;
        while (n % 2 == 0)
            n = n / 2;
    }
    //Now number has to be odd
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        if (n % i == 0) {
            ans = ans^i;
            while (n % i == 0)
                n = n / i;
        }
    }
    //For remaining primes
    if (n > 2) ans = ans^n;
    return ans;
}

int main(){
	lli x;
	scanf("%lld", &x);
	lli ans = getXors(x);
	printf("%lld\n", ans);
}