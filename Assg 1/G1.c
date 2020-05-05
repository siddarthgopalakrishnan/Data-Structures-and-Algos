#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} node;

node * newNode(int data){
    node* newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
//push node at the end of the list
void push(node** head_ref, int data){
    node* temp = newNode(data);
    if(*head_ref == NULL){
        *head_ref = temp;
        return;
    }
    node* curr = *head_ref;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = newNode(data);
    return;
}

void print(node* head){
    node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int removeMult(node* head,int count){
    if(head == NULL){
        return 0;
    }
    node* temp = head;
    node* temp1 = NULL;
    while(temp->next !=NULL){
       // printf("Working on node with data = %d\n", temp->data);
        if(temp->data == temp->next->data)
        {
            temp1 = temp->next;
            temp->next = temp->next->next;
            free(temp1);
            count--;
        }
        else{
            temp = temp->next;
        }
    }
    return count;
}

int main()
{
    int temp;
    char ch;
    node* head = NULL;
    int count = 0;
    while(scanf("%d%c",&temp,&ch)){
        push(&head, temp);
        count++;
        if(ch == '\n')
            break;
    }
    count = removeMult(head, count);
    printf("%d\n", count);
    print(head);
}