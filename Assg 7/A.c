#include<stdio.h>
#include<stdlib.h>

typedef struct order{
	int ono;
	int pri;
	int start;
	int dur;
	struct order* next;
}order;

void Merge(order* arr, int left, int mid, int right){
	int n1 = mid - left + 1;
	int n2 = right - mid;
	order LArr[n1], RArr[n2];
	for (int i = 0; i < n1; i++)
		LArr[i] = arr[left+i];
	for (int i = 0; i < n2; i++)
		RArr[i] = arr[mid+1+i];
	int i = 0, j = 0, k = left;
	while(i < n1 && j < n2)
		if (LArr[i].start < RArr[j].start)
			arr[k++] = LArr[i++];
		else if (LArr[i].start > RArr[j].start)
			arr[k++] = RArr[j++];
		else
			if (LArr[i].pri > RArr[j].pri)
				arr[k++] = LArr[i++];
			else
				arr[k++] = RArr[j++];

	while(i < n1)
		arr[k++] = LArr[i++];
	while(j < n2)
		arr[k++] = RArr[j++];
}

void MergeSort(order* arr, int left, int right){
	if (left < right){
		int mid = (left + right)/2;
		MergeSort(arr, left, mid);
		MergeSort(arr,mid+1, right);
		Merge(arr, left,mid, right);
	}
}

order* addPQ(order* q, order ord){
	order* new = (order*)malloc(sizeof(order));
	*new = ord;
	order* m = (order*)malloc(sizeof(order));
	m->next = q;
	while(m->next != NULL && m->next->pri > new->pri)
		m = m->next;
	printf("IN");

	if (m->next == NULL)
		m->next = new;
	else{
		while(m->next->pri == new->pri && m->next->dur > new->dur)
			m = m->next;
		new->next = m->next;
		m->next = new;
	}
	printf("RET");
	return q;
}

int main(){
	int n;
	scanf("%d",&n);
	order arr[n];
	for (int i = 0; i < n; i++){
		scanf("%d%d%d%d",&arr[i].ono,&arr[i].pri, &arr[i].start, &arr[i].dur);
		arr[i].next = NULL;
	}
	
	MergeSort(arr,0,n-1);
	printf("\n");
	for (int i = 0; i < n; i++)
		printf("%d %d %d %d\n", arr[i].ono,arr[i].pri,arr[i].start,arr[i].dur);

	int j = 0;
	order* qhead = (order*)malloc(sizeof(order));
	*qhead = arr[j++];
	int time = qhead->start;

	while(arr[j].start == time)
		qhead = addPQ(qhead,arr[j++]);
	while(qhead != NULL){
		if (j < n){
			int diff = arr[j].start - (time + qhead->dur);
			if (diff < 0){
				diff = arr[j].start - time;
				time += diff;
				qhead->dur -= diff;
				qhead = addPQ(qhead,arr[j++]);
			}
			else if (diff > 0){
				while(diff > 0){
					time += qhead->dur;
					printf("%d %d\n", qhead->ono, time);
					qhead->dur = 0;
					qhead = qhead->next;
					if(qhead != NULL)
						diff = arr[j].start - (time + qhead->dur);
					else
						break;
				}
			}
			else{
				time+=diff;
				printf("%d %d\n", qhead->ono, time);
				qhead->dur = 0;
				qhead = qhead->next;
				qhead = addPQ(qhead, arr[j++]);
			}
		}
		else{
			time += qhead->dur;
			printf("%d %d\n",qhead->ono, time);
			qhead->dur = 0;
			qhead = qhead->next;
		}
		if (qhead == NULL && j < n){
			time = arr[j].start;
			*qhead = arr[j++];
		}
	}
}