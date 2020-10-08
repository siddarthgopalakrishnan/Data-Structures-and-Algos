/*
	ID - 2017B3A71379H
	Name - Siddarth Gopalakrishnan
*/
#include<stdio.h>
#include<string.h>

int n; // number of nodes
int m; // number of edges
int arr[5003][3]; // array to store values
// arr[i][0] = weight
// arr[i][1] = node u
// arr[i][2] = node v
int parent[5003]; // parent array

void swap(int *a,int *b) // function to swap two elements
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insertion_sort(int i) // implementing insertion sort
{
	while((i>0) && (arr[i][0] < arr[i-1][0]))
	{
		swap(&arr[i][0], &arr[i-1][0]);
		swap(&arr[i][1], &arr[i-1][1]);
		swap(&arr[i][2], &arr[i-1][2]);
		--i;
	}
}

int findParent(int x) // function to get the parent of a node
{
	if(x == parent[x]) return x;
	int par = findParent(parent[x]);
	parent[x] = par;
	return par;
}

int main()
{
	scanf("%d%d", &n, &m);
	memset(parent, -1, sizeof(parent));
	for(int i=0; i<m; ++i)
	{
		scanf("%d%d%d", &arr[i][1], &arr[i][2], &arr[i][0]);
		// initially setting parent of each node as itself
		parent[arr[i][1]] = arr[i][1];
		parent[arr[i][2]] = arr[i][2];
		insertion_sort(i);
	}
	int total=0; // total transition potential
	for(int i=0; i<m; ++i)
	{
		if(i==0) // if no edge has been added, add the first edge
		{
			total += arr[i][0];
			// setting parent of seconf node as that of first node
			parent[arr[i][2]] = parent[arr[i][1]];
			continue;
		}
		// if parents of two nodes are same, continue as they form a cycle
		if(findParent(arr[i][1]) == findParent(arr[i][2])) continue;
		total += arr[i][0];
		// setting parent of second node as that of first node
		parent[findParent(arr[i][2])] = findParent(arr[i][1]);
	}
	printf("\n%d\n", total);
}