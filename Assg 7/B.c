#include<stdio.h>

typedef struct node{
	int ind;
	int price;
}node;

node heap[100001];
int end = -1;

void heapify(int x){
	if(heap[x].price < heap[(x-1)/2].price){
		node t = heap[x];
		heap[x] = heap[(x-1)/2];
		heap[(x-1)/2] = t;
	}
	else if (heap[x].price == heap[(x-1)/2].price){
		if (heap[x].ind > heap[(x-1)/2].ind){
			node t = heap[x];
			heap[x] = heap[(x-1)/2];
			heap[(x-1)/2] = t;
		}
	}
	if (x == 0)
		return;
	x = (x-1)/2;
	heapify(x);
}

void insert(node val){
	heap[++end] = val;
	heapify(end);
}

int minchild(int x){
	if (heap[2*x+1].price < heap[2*x+2].price)
		return 2*x+1;
	else if (heap[2*x+1].price > heap[2*x+2].price)
		return 2*x+2;
	else
		if (heap[2*x+1].ind < heap[2*x+2].ind)
			return 2*x+2;
		else
			return 2*x+1;
}
void heapdown(int x){
	if (2*x+1 > end)
		return;
	if (heap[x].price >= heap[2*x+1].price || heap[x].price >= heap[2*x+2].price){
		int swp = minchild(x);
		node t = heap[x];
		heap[x] = heap[swp];
		heap[swp] = t;
		heapdown(swp);
	}
}

node del(){
	node ret = heap[0];
	heap[0] = heap[end--];
	heapdown(0);
	return ret;
}

int main(){
	int n,m,flag=0;
	scanf("%d %d", &n,&m);
	node new;
	for (int i = 0; i < n; i++){
		scanf("%d",&new.price);
		new.ind = i+1;
		insert(new);
	}
	int fin[n], i = 0;
	node x = del();
	while(end >= -1 && m>=x.price){
		flag = 1;
	 	fin[i++] = x.ind;
		m -= x.price;
		x = del();
	}
	if (!flag){
		printf("NO PARTY");
		return 0;
	}
	printf("%d\n",i);
	for (int j = 0; j < i; j++)
		printf("%d ", fin[j]);
}