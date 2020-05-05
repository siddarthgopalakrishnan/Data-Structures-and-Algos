#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int val;
	struct node* next;
}node;

void splitlist(node* head, node** front, node** back){
	node* slow; node* fast;
	slow = head;
	fast = head->next;
	while(fast != NULL){
		fast = fast->next;
		if(fast != NULL){
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front = head;
	*back = slow->next;
	slow->next = NULL;
}

node* sorted(node* a, node* b){
	node* temp = (a->val)>=(b->val)?b:a;
	node* head = temp;
	if(a->val < b->val) a = a->next;
	else b = b->next;
	while(a != NULL && b!= NULL){
		if(a->val > b->val){
			temp->next = b;
			temp = temp->next;
			b = b->next;
		}
		else{
			temp->next = a;
			temp = temp->next;
			a = a->next;
		}
	}
	if(a == NULL) temp->next = b;
	else temp->next = a;
	return head;
}

void mergesort(node** head){
	node* h = *head;
	if(h == NULL || h->next == NULL) return;
	node* a; node* b;
	splitlist(h, &a, &b);
	mergesort(&a); mergesort(&b);
	*head = sorted(a, b);
}

void addNode(node** head, int x){ // inserted element at the start, not at end
	node* n = (node*)malloc(sizeof(node));
	n->val = x;
	n->next = (*head);
	(*head) = n;
}

void print(node* head){
	node* head1 = head;
	while(head1!=NULL){
		printf("%d ", head1->val);
		head1 = head1->next;
	}
}

int main(){
	int num;
	node* head = NULL;
	while(scanf("%d", &num)){
		char c = getchar();
		addNode(&head, num);
		if(c == '\n') break;
	}
	mergesort(&head);
	print(head);
	printf("\n");
}