#include<stdio.h>

int stack[1000001];
int sptr=-1;

void push(int x)
{
	stack[++sptr] = x;
	return;
}

int pop()
{
	if(sptr == -1) return -1;
	int copy = stack[sptr];
	stack[sptr--] = 0;
	return copy;
}

int main()
{
	int n; scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int pos=0;
	for(int i=1; i<n; i++)
	{
		if(arr[i] == arr[i-1])
		{
			push(arr[i]);
			pos = i;
		}
		else
		{
			arr[pos++] = arr[i];
			int temp = pop();
			if(temp != -1) arr[pos++] = temp;
			else continue;
		}
	}
	while(sptr!=-1)
	{
		arr[pos++] = pop();
		if(arr[pos-1] == arr[pos-2])
		{
			printf("%d\n", -1);
			return 0;
		}
	}
	for(int i=0; i<pos; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}