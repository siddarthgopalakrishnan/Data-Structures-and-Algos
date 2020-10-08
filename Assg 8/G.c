#include<stdio.h>
#include<limits.h>

int n;
int isMinHeap(int arr[], int i, int n)
{
	if(2*i+2>n) return 1;
	if(arr[i]<=arr[2*i+1] && arr[i]<=arr[2*i+2] && isMinHeap(arr, 2*i+1, n) && isMinHeap(arr, 2*i+2, n))
		return 1;
	return 0;
}

int isMaxHeap(int arr[], int i, int n)
{
	arr[n] = INT_MIN;
	arr[n+1] = INT_MIN;
	if(2*i+2>n) return 1;
	if(arr[i]>=arr[2*i+1] && arr[i]>=arr[2*i+2] && isMaxHeap(arr, 2*i+1, n) && isMaxHeap(arr, 2*i+2, n))
		return 1;
	return 0;
}

int main()
{
	scanf("%d", &n); int arr[n];
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	int ismin = isMinHeap(arr, 0, n);
	int ismax = isMaxHeap(arr, 0, n);
	if(ismin && ismax) printf("BOTH\n");
	else if(!ismax && ismin) printf("MIN_HEAP\n");
	else if(!ismin && ismax) printf("MAX_HEAP\n");
	else printf("TRICK_QUESTION\n");
	return 0;
}