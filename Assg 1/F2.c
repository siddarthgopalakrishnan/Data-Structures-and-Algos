#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} node;

node* newNode(int data){
    node* newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void push(node** head_ref, int data){
    //accepting in reverse
    node* new_node = newNode(data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    return;
    // node* temp = newNode(data);
    // if(*head_ref == NULL){
    //     *head_ref = temp;
    //     return;
    // }
    // node* curr = *head_ref;
    // while(curr->next != NULL){
    //     curr = curr->next;
    // }
    // curr->next = newNode(data);
    // return;
}

void print(node* head){
    if(head == NULL) return;
    print(head->next);
    printf("%d ", head->data);
    // node* temp = head;
    // while(temp != NULL){
    //     printf("%d ", temp->data);
    //     temp = temp->next;
    // }
    printf("\n");
}

node* addLists(node* first, node* second)
{
    node* res = NULL;//head node of answer
    node* temp=NULL, *prev=NULL;
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

int main()
{
    int temp;
    char ch;
    node* head1 = NULL;
    node* head2 = NULL;
    while(scanf("%d%c",&temp,&ch)){
        push(&head1, temp);
        if(ch == '\n')
            break;
    }
    while(scanf("%d%c",&temp,&ch)){
        push(&head2, temp);
        if(ch == '\n')
            break;
    }
    print(head1);
    print(head2);
    node* res=NULL;
    res=addLists(head1, head2);
    print(res);
}
