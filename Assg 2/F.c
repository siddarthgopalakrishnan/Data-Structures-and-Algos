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

void traverse(struct node * head)
{	
	struct node * currentNode = head;
	while(currentNode != NULL)
	{
		printf("%d ",currentNode->val);
		currentNode = currentNode->next;
	}
	printf("\n");
}

void  merge(	struct node * head1,struct node * head2){
		struct node * final = (struct node*)malloc(sizeof(struct node));
		struct node * final_trav = final;

	int flag = 0;
		
		while(head1 != NULL && head2 != NULL){
			if(head1->val < head2->val){
				if(flag==0){
					flag++;
					final_trav->val = head1->val;
					final_trav->next = NULL;
					final_trav->prev = NULL;
					head1 = head1->next;
				}else{
					final_trav = createList(head1->val,final_trav);
					head1 = head1->next;	
				}
				
			}else{
				if(flag==0){
					flag++;
					final_trav->val = head2->val;
					final_trav->next = NULL;
					final_trav->prev = NULL;
					head2 = head2->next;
				}else{
					final_trav = createList(head2->val,final_trav);
					head2 = head2->next;	
				}
				

			}
		}
		
		
		if(head1==NULL){
			while(head2!=NULL){
				final_trav = createList(head2->val,final_trav);
				head2 = head2->next;
			}
		}else{
			while(head1!=NULL){
				final_trav = createList(head1->val,final_trav);
				head1 = head1->next;
			}			
		}

	traverse(final);

	return;
	
	
}



int main()
{
	int n = 0,a;
	char temp;

	struct node * head1 = (struct node*)malloc(sizeof(struct node));
	struct node * lastNode1 = head1;
	while(1)
	{
		scanf("%d%c",&a,&temp);
		n++;
		

		if(n != 1)
		{
			lastNode1 = createList(a,lastNode1);
		}
		else
		{
			head1->val = a;
			head1->next = NULL;
			head1->prev = NULL;
		}
		if(temp == '\n')
			break;
	}
	
	n=0;
	struct node * head2 = (struct node*)malloc(sizeof(struct node));
	struct node * lastNode2 = head2;
	while(1)
	{
		scanf("%d%c",&a,&temp);
		n++;
		

		if(n != 1)
		{
			lastNode2 = createList(a,lastNode2);
		}
		else
		{
			head2->val = a;
			head2->next = NULL;
			head2->prev = NULL;

		}
		if(temp == '\n')
			break;
	}
	
	merge(head1,head2);
	
}
