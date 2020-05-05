#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node * next;
    struct node * prev;
}Node;

Node * head;
Node * tail;

void addNode(int x)
{
    if(head==NULL)
    {
        head = (Node *) malloc(sizeof(Node));
        head->data = x;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    }
    else
    {
        Node * c = (Node *) malloc(sizeof(Node));
        c->data = x;
        c->prev = tail;
        c->next = NULL;
        tail->next = c;
        tail = c;
    }
}
void print(Node * h)
{
    Node * h_copy = h;
    while(h_copy!=NULL)
    {
        printf("%d",h_copy->data);
        printf(" ");
        h_copy=h_copy->next;
    }
}
void print_till(Node * h)
{
    Node * h_copy = head;
    while(h_copy!=h)
    {
        printf("%d",h_copy->data);
        printf(" ");
        h_copy=h_copy->next;
    }
}
int main()
{
    int x;
    char c;
    int cnt=0;
    while(1)
    {
        scanf("%d",&x);
        addNode(x);
        cnt++;
        c = getchar();
        if(c=='\n')
            break;
    }
    scanf("%d",&x);
    scanf(" %c",&c);
    x = x%cnt;
    if(c=='R')
        x=cnt-x;
    int cpy = x;
    Node * hc =head;
    while(cpy--)
        hc=hc->next;
    print(hc);
    print_till(hc);
}
