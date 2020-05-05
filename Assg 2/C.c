#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int val;
	struct node* next;
}node;

node* head;

void printList(){
	if (head != NULL){
		node* n = (node*)malloc(sizeof(node));
		n = head;
		while(n!=NULL){
			printf("%d ", n->val);
			n = n->next;
		}
	}
	printf("\n");
}

void add(int v){
	if (head == NULL){
		head = (node*)malloc(sizeof(node));
		head->val = v;
		head->next = NULL;
	}
	else{
		node* m = (node*)malloc(sizeof(node));
		m->val = v;
		m->next = NULL;
		node* n = head;
		while(n->next!=NULL)
			n = n->next;
		n->next = m;
	}
	printList();
}

void insert(int v, int loc){
	node* n = (node*)malloc(sizeof(node));
	if (loc == 1){
		n->val = v;
		n->next = head;
		head = n;
	}
	else{
		n = head;
		for (int i = 1; i<loc-1; i++)
			n = n->next;
		node* new = (node*)malloc(sizeof(node));
		new->val = v;
		new->next = n->next;
		n->next = new;
	}
	printList();
}

void rem(int v){
	int first = 0;
	int last = 0;
	int flag = 0;
	node* n = (node*)malloc(sizeof(node));
	n = head;
	for(int i = 1; n != NULL; i++){
		if (n->val == v){
			flag = 1;
			if(!first)
				first = i-1;
			else
				last = i-1;
		}
		n = n->next;
	}
	node* m = (node*)malloc(sizeof(node));
	m = head;
	for (int i = 1; m != NULL;i++){
		if (i == first || i == last-1)
			m->next = m->next->next;
		m = m->next;
	}
	if (flag != 0)
		printList();
	else
		printf("Element not found\n");
}

void rev(){
    // if(head == NULL) return;
    // print(head->next);
    // printf("%d ", head->data);
    // printf("\n");
	node* ye;
	node* agla;
	node* pichla;
	ye = head, agla = NULL; pichla = NULL;
	while(ye != NULL){
		agla = ye->next;
		ye->next = pichla;
		pichla = ye;
		ye = agla;
	}
	head = pichla;
	printList();
}

int fetch(int loc){
	node* n = (node*)malloc(sizeof(node));
	n = head;
	for (int i = 1; i < loc; i++)
		n = n->next;
	return n->val;
}

int main(){
	int n;
	scanf("%d", &n);
	char str[10] = {};
	int v, loc;
	for (int i = 0; i < n; i++) {
		scanf("%s", &str);
		switch(str[2]){
			case 'd': // add
				scanf("%d", &v);
				add(v);
				break;
			case 's': // insert
				scanf("%d %d", &v, &loc);
				insert(v, loc);
				break;
			case 't': // fetch
				scanf("%d", &loc);
				printf("%d\n",fetch(loc));
				break;
			case 'm':
				scanf("%d", &v);
				rem(v);
				break;
			case 'v':
				rev();
		}
	}
}