#include<stdio.h>

typedef struct point{
	int num;
	int x;
	int y;
	double slope;
}point;

void Merge (point* arr, int left, int mid, int right){
	int n1 = mid - left + 1;
	int n2 = right - mid;
	point LArr[n1];
	point RArr[n2];
	for (int i = 0; i < n1; i++)
		LArr[i] = arr[left+i];
	for (int i = 0; i < n2; i++)
		RArr[i] = arr[mid + 1 + i];
	int i = 0, j = 0, k = left;
	while(i != n1 && j != n2){
		if (LArr[i].slope < RArr[j].slope)
			arr[k++] = LArr[i++];
		else if (LArr[i].slope > RArr[j].slope)
			arr[k++] = RArr[j++];
		else
			if (LArr[i].x < RArr[j].x)
				arr[k++] = LArr[i++];
			else
				arr[k++] = RArr[j++];
	}
	while(i != n1)
		arr[k++] = LArr[i++];
	while(j != n2)
		arr[k++] = RArr[j++];
}

void MergeSort(point* arr, int left, int right){
	if (left < right){
		int mid = (left + right)/2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid+1, right);
		Merge(arr, left, mid, right);
	}
	else return;
}

int main(){
	int n;
	scanf("%d", &n);
	point pts[n+1];
	int xp,yp,p,min = 1e9, bp;
	for (int i = 0; i < n; i++){
		scanf("%d %d %d", &p,&xp,&yp);
		pts[p].num = p;
		pts[p].x = xp;
		pts[p].y = yp;
		if (yp < min){
			min = yp;
			bp = p;
		}
	}

	for (int i = 1; i <= n; i++)
		if (i != bp){
			pts[i].y += -1*pts[bp].y;
			pts[i].x -= pts[bp].x;
		}

	pts[bp].x = 0;
	pts[bp].y = 0;

	for (int i = 1; i <= n; i++){
		int temp = pts[i].x;
		pts[i].x = pts[i].y;
		pts[i].y = -temp;
	}

	for (int i = 1; i <= n; i++)
		if (!pts[i].x)
			pts[i].slope = 1e9;
		else
			pts[i].slope = (double) pts[i].y/pts[i].x;

	MergeSort(pts, 1, n);

	for (int i = 1; i <= n; i++)
		if (pts[i].num != bp)
			printf("%d ", pts[i].num);
}