#include<stdio.h>

int heap[200001];
int end = -1;

void heapify(int ind){
	if (ind <= 0 || heap[ind] >= heap[(ind-1)/2])
		return;

	int t = heap[ind];
	heap[ind] = heap[(ind-1)/2];
	heap[(ind-1)/2] = t;
	ind = (ind-1)/2;
	heapify(ind);
}
void insert(int val){
	heap[++end] = val;
	if (end == 0)
		return;
	heapify(end);
}

int minchild(int this){
	if (heap[2*this+1] < heap[2*this + 2])
		return 2*this+1;
	else
		return 2*this+2;
}
void heapdown(int ind){
	if (2*ind+1 > end)
		return;
	if (heap[ind] >= heap[2*ind+1] || heap[ind] >= heap[2*ind+2]){
		int swp = minchild(ind);
		int t = heap[swp];
		heap[swp] = heap[ind];
		heap[ind] = t;
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
	int n,x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d",&x);
		insert(x);
	}

	while(end != -1)
		printf("%d ", delete());
}