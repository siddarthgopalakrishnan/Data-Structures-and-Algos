#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int val;
	struct node* next;
}node;

node* n;

int spiral(node* m){
	int i = 0;
	if (m->next != NULL)
		i = spiral(m->next);
	if (i == 0){
		m->next = n->next;
		n->next = m;
		n = m->next;
		if (n == m){
			m->next = NULL;
			i = 1;
		}
	}
	return i;
}

int main(){
	char ch;
	int x;
	scanf("%d%c", &x, &ch);
	node* head = (node*)malloc(sizeof(node));
	n = head;
	head->val = x;
	head->next = NULL;
	node* m = head;
	while(ch!='\n'){
		scanf("%d%c", &x, &ch);
		node* new = (node*)malloc(sizeof(node));
		m->next = new;
		new->val = x;
		new->next = NULL;
		m = m->next;
	}
	spiral(head);
	m = head;
	while(m != NULL){
		printf("%d ", m->val);
		m = m->next;
	}
}