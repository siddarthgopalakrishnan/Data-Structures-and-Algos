#include<stdio.h>

int getPivot(int arr[], int l, int r){
	if(l>r) return -1;
	if(l==r) return l;
	int mid = (l+r)/2;
	if(mid<r && arr[mid] > arr[mid+1]) return mid;
	if(mid>l && arr[mid] < arr[mid-1]) return mid-1;
	if(arr[l] >= arr[mid]) return getPivot(arr, l, mid-1);
	return getPivot(arr, mid+1, r);
}

int binsearch(int arr[], int l, int r, int z){
	if(r<l) return -1;
	int mid = (l+r)/2;
	if(arr[mid] == z) return mid;
	if(z > arr[mid]) return binsearch(arr, mid+1, r, z);
	return binsearch(arr, l, mid-1, z);
}

int search(int arr[], int n, int z)
{
	int pivot = getPivot(arr, 0, n-1);
	if(pivot == -1) return binsearch(arr, 0, n-1, z);
	if(arr[pivot] == z) return pivot;
	if(arr[0] < z) return binsearch(arr, 0, pivot-1, z);
	return binsearch(arr, pivot+1, n-1, z);
}

int main(){
	int n, z;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; ++i){
		scanf("%d", &arr[i]);	
	}
	scanf("%d", &z);
	int index = search(arr, n, z);
	if(index == -1) printf("NO\n");
	else printf("YES\n%d\n", index);
}