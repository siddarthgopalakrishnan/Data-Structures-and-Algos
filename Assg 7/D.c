#include<stdio.h>

int heap[100001];
int end = -1;

void heapify(int x){
	if (heap[x] > heap[(x-1)/2]){
		int t = heap[x];
		heap[x] = heap[(x-1)/2];
		heap[(x-1)/2] = t;
	}
	if (!x)
		return;
	x = (x-1)/2;
	heapify(x);
}
int maxchild(int x){
	if (heap[2*x+1] > heap[2*x+2])
		return 2*x+1;
	else
		return 2*x+2;
}
void heapdown(int x){
	if (2*x+1 > end)
		return;
	if (heap[x] < heap[2*x+1] || heap[x] < heap[2*x+2]){
		int swp = maxchild(x);
		int t = heap[x];
		heap[x] = heap[swp];
		heap[swp] = t;
		heapdown(swp);
	}
}
int delete(){
	int ret = heap[0];
	heap[0] = heap[end--];
	heapdown(0);
	return ret;
}
int main(){
	int n,m,x,sum = 0;
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++){
		scanf("%d",&heap[++end]);
		heapify(end);
	}
	while(m--){
		int rem = delete();
		sum+=rem;
		heap[++end] = rem/3;
		heapify(end);
	}
	printf("%d", sum);
}