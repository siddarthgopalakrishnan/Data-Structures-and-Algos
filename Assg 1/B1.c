#include<stdio.h>

int isPrime(long int x){
	int flag=0;
	for(int i=2; i<=x/2; i++){
		if(x%i == 0){
			flag=1;
			break;
		}
	}
	if(!flag) return 1;
	else return 0;
}

int main() {
	long int a,b;
	long int freq[10] = {0};
	scanf("%ld %ld", &a, &b);
	for(long int i=a; i<=b; i++){
		if(isPrime(i)){
			long int copy=i;
			while(copy!=0){
				freq[copy%10]++;
				copy /= 10;
			}
		}
	}
	long int max=0;
	int digit;
	for(long int i=0; i<10; i++){
		if(freq[i]>max){
			max=freq[i];
			digit=i;
		}
	}
	printf("%d %ld\n", digit, max);
	return 0;
}