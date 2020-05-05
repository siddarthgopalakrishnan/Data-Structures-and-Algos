#include<stdio.h>
#include<string.h>
#include<math.h>
#define lli long long int

void toGrey(lli n){
	lli copy = n;
	lli sum[33] = {0};
	int i=0;
	while(copy != 0){
		sum[i] = (copy%2);
		copy /= 2;
		i++;
	}
	if(i == 0) printf("%d", sum[i]);
	for(i = i-1; i>=0; i--){
		printf("%d", (sum[i]^sum[i+1]));
	}
	printf("\n");
	return;
}

void toDec(char c[]){
	int i=0;
	int bin[33];
	while(c[i]!='\0'){
		if(i==0){
			bin[i] = c[i]-'0';
		}else if(c[i]=='0'){
			bin[i] = bin[i-1];
		}else{
			bin[i]  = 1-(bin[i-1]);
		}
		i++;
	}
	lli decimal = 0;
	i--;int j = 0;
	while(i>=0){
		decimal += pow(2,j)*bin[i];
		i--; j++;
	}
	printf("%lld\n",decimal);
	return;
}

int main(){
	int q;
	char temp;
	scanf("%d%c", &q, &temp);
	for(int i=0; i<q; i++){
		char c;
		scanf("%s", &c);
		if (c == 'G'){
			lli n;
			scanf("%lld", &n);
			toGrey(n);
		}
		else{
			char str[32];
			scanf("%s", str);
			toDec(str);
		}
	}
	return 0;
}