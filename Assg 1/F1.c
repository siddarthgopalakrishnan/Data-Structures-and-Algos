#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node* next;
} node;

//Creating new node
node *newNode(int data)
{
	node *new_node = (node *)malloc(sizeof(node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

//inserting a node at the beginning of the list
void push(node** head_ref, int new_data)
{
	node* temp = (node*)malloc(sizeof(node));
	if(temp == NULL) return;
	else{
		temp->data = new_data;
		temp->next = *head_ref;
		*head_ref = temp;
	}
}

node* addLists(node* first, node* second)
{
	node* res = NULL;//head node of answer
	node* temp, *prev=NULL;
	int carry=0, sum;
	while(first!=NULL || second!=NULL)
	{
		int x = first?first->data:0;
		int y = second?second->data:0;
		sum = carry ^ x ^ y;
		carry = (x&y)|(x&carry)|(carry&y);
		temp = newNode(sum);
		if(res == NULL) res=temp;
		else prev->next = temp;
		prev=temp;
		if(first) first = first->next;
		if(second) second = second->next;
	}
	if(carry == 1)
		temp->next = newNode(carry);
	return res;
}

void printlist(node *head)
{
	if(head == NULL) return;
    printlist(head->next);
    printf("%d", head->data);
}

int main()
{
	node* res=NULL;
	node* first=NULL;
	node* second=NULL;
	char ch;
	while(scanf("%c",&ch)){// taking first no.
        if(ch == '1') push(&first, 1);
        else if(ch == '0') push(&first, 0);
        else if(ch == '\n') break;
    }
    while(scanf("%c",&ch)){//taking second no.
        if(ch == '1') push(&second, 1);
        else if(ch == '0') push(&second, 0);
        else if(ch == '\n') break;
    }
    printf("A: ");
    printlist(first);
    printf("\n"); 
    printf("B: ");
    printlist(second);
    printf("\n");
    res = addLists(first, second); 
    printf("Resultant list is: "); 
    printlist(res);
    printf("\n");
    return 0; 
}