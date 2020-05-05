#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int val;
	struct node* next;
}node;

node* head;
node* tail;

void addNode(int val){
	if(head == NULL){
		head = (node* )malloc(sizeof(node));
		head->val = val;
		head->next = NULL;
		tail = head;
	}
	else{
		node* n = head;
		while(n->next != NULL){
			n = n->next;
		}
		node* temp = (node*)malloc(sizeof(node));
		temp->val = val;
		temp->next = NULL;
		n->next = temp;
		tail = temp;
	}
}

int main(){
	int x, len;
	while(scanf("%d", &x)){
		addNode(x);
		char c = getchar();
		len++;
		if(c == '\n') break;
	}
	int i=0;
	node* temp = head;
	while(i != len/2){
		tail->next = temp->next;
		temp->next = tail;
		temp = tail->next;
		node* q = temp;
		while(q->next != tail){
			q = q->next;
		}
		tail = q;
		tail->next = NULL;
		i++;
	}
	temp = head;
	while(temp != NULL){
		printf("%d ", temp->val);
		temp = temp->next;
	}
	printf("\n");
}