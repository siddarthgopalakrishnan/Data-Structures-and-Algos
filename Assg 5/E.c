#include<stdio.h>
void merge(int arr[], int l, int m, int r){
	int n1 = m-l+1; int n2 = r-m;
	int L[n1], R[n2];
	for(int i=0; i<n1; i++){
		L[i] = arr[l+i];
	}
	for(int i=0; i<n2; i++){
		R[i] = arr[m+1+i];
	}
	int i=0, j=0, k=l;
	while(i<n1 && j<n2){
		if(L[i]<=R[j])
			arr[k++] = L[i++];
		else arr[k++] = R[j++];
	}
	while(i<n1) arr[k++] = L[i++];
	while(j<n2) arr[k++] = R[j++];
}
void mergesort(int arr[], int l, int r){
	if(l<r){
		int mid = (l+r)/2;
		mergesort(arr, l, mid);
		mergesort(arr, mid+1, r);
		merge(arr, l, mid, r);
	}
}
int search(int toll[], int num, int l, int r){
	if(l<=r){
		int mid = (l+r)/2;
		if(toll[mid] == num) return mid;
		else if(toll[mid] > num){
			return search(toll, num, 0, mid-1);
		}
		return search(toll, num, mid+1, r);
	}
	return -1;
}
int main(){
	int n,m,l;
	int u,v,a,b,k;
	scanf("%d %d %d", &n, &m, &l);
	int toll[m], gas[l];
	scanf("%d %d %d %d %d", &u, &v, &a, &b, &k);
	for(int i=0; i<m; i++){
		scanf("%d", &toll[i]);
	}
	for(int i=0; i<l; i++){
		scanf("%d", &gas[i]);
	}
	mergesort(toll, 0, m-1);
	mergesort(gas, 0, l-1);

	int i = search(toll, u, 0, m-1);
	int j, litres=0, flag=1;
	while(toll[i] != v){
		if((toll[i] + a*gas[l-1] + b) < toll[i+1])
		{
			flag=0; break;
		}
		for(j=0; j<l; j++){
			if((toll[i] + a*gas[j] + b) >= toll[i+1]){
				litres = litres + gas[j];
				i++;
				break;
			}
		}
	}
	if(!flag) printf("NOT POSSIBLE");
	else printf("%d\n", (k*litres));
}