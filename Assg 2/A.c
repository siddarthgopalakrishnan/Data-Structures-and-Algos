#include <stdio.h>
#include <limits.h>
#include<stdlib.h>

struct node
{
	int val;
	struct node * next;
	struct node * prev;
};

struct node * createList(int a, struct node *lastNode)
{
	struct node * currentNode = (struct node*)malloc(sizeof(struct node));
	currentNode->val = a;
	currentNode->next = NULL;
	currentNode->prev = lastNode;
	lastNode->next = currentNode;
	return currentNode;
}

void find_and_traverse(int n, int index,struct node * head)
{	
	struct node * currentNode = head;
	int cnt = -1;
	while(cnt!=index)
	{
		if(cnt==-1){
			cnt++;
			continue;
		}
		
		currentNode = currentNode->next;
		cnt++;
	}
	
	cnt = 0;
	while(cnt!=n){
		printf(" %d ",currentNode->val);
		if(currentNode->next == NULL)
			currentNode = head;
		else
			currentNode = currentNode->next;
		cnt++;
	}
	
	
	printf("\n");
}

int main()
{
	int n = 0,a;
	char temp;

	struct node * head = (struct node*)malloc(sizeof(struct node));
	struct node * lastNode = head;
	while(1)
	{
		scanf("%d%c",&a,&temp);
		n++;
		

		if(n != 1)
		{
			lastNode = createList(a,lastNode);
		}
		else
		{
			head->val = a;
			head->next = NULL;
			head->prev = NULL;
		}
		if(temp == '\n')
			break;
	}
	
	int k;char c,temp1;
	scanf("%d%c%c%c",&k,&temp,&c,&temp1);
	int index;
	if(c=='L')
		index = k%n;
	else
		index = n - (k%n);
				
	find_and_traverse(n,index,head);
}