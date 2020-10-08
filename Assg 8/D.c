#include<stdio.h>

int n,m;
int x[27];
int main() {
	scanf("%d %d", &n, &m);
	char y[m];
	char c; 
	char dummy; scanf("%c", &dummy);
	for(int i=0; i<n; i++) {
		scanf("%c", &c);
		if(c!=' ')
			x[c-'a'] = 1;
		else
			i--;
	}
	scanf("%c", &dummy);
	for(int i=0; i<m; i++) {
		scanf("%c", &c);
		if(c!=' ')
			y[i] = c;
		else
			i--;
	}
	for(int i=0; i<m; i++) {
		if(!x[y[i]-'a'])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}