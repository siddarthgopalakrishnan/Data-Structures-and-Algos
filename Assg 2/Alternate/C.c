#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node * next;
}Node;
Node * head;
Node * tail;
void add(int x)
{
    if(head==NULL)
    {
        head = (Node *) malloc(sizeof(Node));
        head->data = x;
        head->next=NULL;
        tail = head;
    }
    else
    {
        tail->next = (Node *) malloc(sizeof(Node));
        tail= tail->next;
        tail->data = x;
        tail->next=NULL;
    }
}
void insert(int index,int x)
{
    if(head==NULL&&index==1)
    {
        add(x);
    }
    else if(index==1)
    {
        Node * c = (Node *) malloc(sizeof(Node));
        c->data = x;
        c->next = head;
        head = c;
    }
    else
    {
        int i = index - 1;
        Node * c = (Node *) malloc(sizeof(Node));
        c->data = x;
        Node * curr = head;
        Node * nxt = head->next;
        while(--i)
        {
            curr=curr->next;
            nxt = nxt->next;
        }
        curr->next = c;
        c->next = nxt;
    }
}
int remove_1(int x)
{
    if(head==NULL)
    {
        printf("ELEMENT NOT FOUND\n");
        return 1;
    }
    else
    {
        int flag = 0;
        Node * curr = head;
        Node * first_prev;
        Node * first;
        Node * last_prev;
        Node * last;
        if(head->data==x)
        {
            first_prev = NULL;
            first = head;
            last_prev = curr;
            last = curr->next;
            flag = 1;
        }
        while(curr->next!=NULL)
        {
            if(curr->next->data==x)
            {
                if(flag==0)
                {
                    first_prev = curr;
                    first = curr->next;
                    last_prev = curr;
                    last = curr->next;
                    flag = 1;
                }
                else
                {
                    last_prev = curr;
                    last = curr->next;
                }
            }
            curr = curr->next;
        }
        if(flag==0)
        {
            printf("ELEMENT NOT FOUND\n");
            return 1;
        }
        if(first_prev!=NULL)
        {
            first_prev->next = first->next;
        }
        else
        {
            head=head->next;
        }
        if(first==last)
            return 0;
        else
        {
            last_prev->next = last->next;
        }
    }
    return 0;
}
void reverse()
{
    if(head!=NULL&&head->next!=NULL)
    {
        Node * prev = head;
        tail = head;
        Node * curr = head->next;
        Node * nxt = curr->next;
        while(curr!=NULL)
        {
            curr->next =prev;
            prev= curr;
            curr = nxt;
            if(nxt!=NULL)
                nxt=nxt->next;
        }
        head = prev;
        tail->next = NULL;
    }
}
int fetch(int index)
{
    int i = index;
    Node * curr = head;
    while(--i)
    {
        curr = curr->next;
    }
    return curr->data;
}
void print()
{
    Node * curr = head;
    while(curr!=NULL)
    {
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("\n");
}
int main()
{
    add(3);
    print();
    add(4);
    print();
    add(6);
    add(7);
    print();
    reverse();
    print();
    add(7);
    print();
    add(5);
    print();
    remove_1(7);
    print();
    add(3);
    print();
    printf("%d\n",fetch(4));
    insert(2,18);
    print();
}
