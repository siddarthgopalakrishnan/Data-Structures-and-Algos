#include<stdio.h>

int heap[100002] = {};
int end = -1;
int swp = 0;

void heapify(int x){
	if (heap[(x-1)/2] > heap[x]){
		swp++;
		int temp = heap[(x-1)/2];
		heap[(x-1)/2] = heap[x];
		heap[x] = temp;
		x = (x-1)/2;
		if (x == 0)
			return;
		else
			heapify(x);
	}
}
int insert(int val){
	heap[++end] = val;
	heapify(end);
}
int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d",&arr[i]);
	for (int i = 0; i < n; i++)
		insert(arr[i]);

	for (int i = 0; i < n; i++)
		if (heap[2*i+1] > heap[2*i+2])
			swp++;
	printf("%d", swp);
}