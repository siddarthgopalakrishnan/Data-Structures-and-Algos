#include<stdio.h>
#include<stdlib.h>

int comparator_inc(const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}
int comparator_dec(const void * a, const void * b){
   return ( *(int*)b - *(int*)a );
}
int ele[100];
void clear_ele(){
	for(int i=0;i<100;i++)
		ele[i] = -1;
}
int main(){
	int n,i,j,zcount = 0;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0)
			zcount++;
	}
    qsort(a, n, sizeof(int), comparator_inc);
    if(zcount==0){
    	printf("NO NUMBER");
    	return 0;
	}
	n = n-zcount;
	int b[n];
	for(i = 0;i<n;i++){
		b[i] = a[zcount + i];
	}
	int maxlen=-99,maxsum = -99;
    for (i = 0; i < (1<<n); i++) 
    { 
    	int sum = 0,cnt = 0;
        for (j = 0; j < n; j++) {
        	if ((i & (1 << j)) > 0) {
				sum += b[j];cnt++;
			}
		}
		if(sum%3==0 && cnt==maxlen && sum>maxsum && sum!=0){
			maxlen = cnt;
			maxsum = sum;
			clear_ele();
			int counter = 0;
			for (j = 0; j < n; j++){
    			if ((i & (1 << j)) > 0){
					ele[counter] = b[j];
					counter++;
				}
			}	
		}
		else if(sum%3==0 && cnt > maxlen && sum!=0){
			maxlen = cnt;
			maxsum = sum;
			clear_ele();
			int counter = 0;
			for (j = 0; j < n; j++) {
    			if ((i & (1 << j)) > 0) {
					ele[counter] = b[j];
					counter++;
				}
			}	
		}
	}
	if(maxlen < 1){
		printf("NO NUMBER");
		return 0;
	}
    qsort(ele, maxlen, sizeof(int), comparator_dec); 
	for(int i=0;i<maxlen;i++)
    	printf("%d",ele[i]);
    for(int i = 0;i<zcount;i++)
    	printf("0");
	return 0;
}