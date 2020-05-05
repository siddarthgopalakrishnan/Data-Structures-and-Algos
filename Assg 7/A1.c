#include<stdio.h>

typedef struct order{
	int num;
	int pri;
	int start;
	int dur;
}order;

void Merge(order* arr, int left, int mid, int right){
	int n1 = mid - left +1;
	int n2 = right - mid;
	order LArr[n1], RArr[n2];
	for (int i = 0; i < n1; i++)
		LArr[i] = arr[left + i];
	for (int i = 0; i < n2; i++)
		RArr[i] = arr[mid+1+i];
	int i = 0, j = 0, k = left;
	while(i < n1 && j < n2){
		if (LArr[i].start < RArr[j].start)
			arr[k++] = LArr[i++];
		else if (LArr[i].start > RArr[j].start)
			arr[k++] = RArr[j++];
		else
			if (LArr[i].pri > RArr[i].pri)
				arr[k++] = LArr[i++];
			else
				arr[k++] = RArr[j++];
	}
	while(i<n1)
		arr[k++] = LArr[i++];
	while(j < n2)
		arr[k++] = RArr[j++];
}

void MergeSort(order* arr, int left, int right){
	if (left < right){
		int mid = (left + right)/2;
		MergeSort(arr, left, mid);
		MergeSort(arr,mid+1, right);
		Merge(arr, left, mid, right);
	}
}

order heap[100001];
int end = -1;

int maxchild(int this){
	if (heap[2*this+1].pri > heap[2*this+2].pri)
		return 2*this+1;
	else if(heap[2*this+1].pri < heap[2*this+2].pri)
		return 2*this+2;
	else
		if (heap[2*this+1].dur < heap[2*this+2].dur)
			return 2*this + 1;
		else
			return 2*this+2;
}

void heapdown(int ind){
	if (2*ind+1 > end)
		return;
	if(heap[ind].pri < heap[2*ind+1].pri || heap[ind].pri < heap[2*ind+2].pri || heap[ind].pri == heap[2*ind+1].pri || heap[ind].pri == heap[2*ind+2].pri){
		int swp = maxchild(ind);
		order tmp = heap[ind];
		heap[ind] = heap[swp];
		heap[swp] = tmp;
		heapdown(swp);
	}
	else
		return;
}

void del_top(){
	int i = 0, flag = 0;
	order ret = heap[0];
	heap[0] = heap[end--];
	heapdown(0);
}

void heapify(int ind){
	if (heap[(ind-1)/2].pri < heap[ind].pri){
		order tmp = heap[ind];
		heap[ind] = heap[(ind-1)/2];
		heap[(ind-1)/2] = tmp;
	}
	if (ind == 0)
		return;
	ind = (ind-1)/2;
	heapify(ind);
}

void h_insert(order val){
	heap[++end] = val;
	heapify(end);
}

int main(){
	int n;
	scanf("%d",&n);
	order arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d%d%d%d",&arr[i].num, &arr[i].pri, &arr[i].start, &arr[i].dur);
	MergeSort(arr,0,n-1);
	int j = 0, time = arr[0].start;
	while(j < n && arr[j].start == time)
		h_insert(arr[j++]);
	
	while(end != -1){
		if (j < n){
			int diff = arr[j].start - (time + heap[0].dur);
			if (diff < 0){
				diff = arr[j].start - time;
				time+=diff;
				heap[0].dur -= diff;
				h_insert(arr[j++]);
			}
			else if(diff > 0){
				while(diff > 0){
					time += heap[0].dur; 
					printf("%d %d\n", heap[0].num, time);
					heap[0].dur = 0;
					del_top();
					diff = arr[j].start - (time + heap[0].dur);
				}
			}
			else{
				time += heap[0].dur;
				printf("%d %d\n", heap[0].num, time);
				heap[0].dur = 0;
				del_top();
				h_insert(arr[j++]);
			}
		}
		else {
			time += heap[0].dur;
			printf("%d %d\n", heap[0].num, time);
			heap[0].dur = 0;
			del_top();
		}
	}
}