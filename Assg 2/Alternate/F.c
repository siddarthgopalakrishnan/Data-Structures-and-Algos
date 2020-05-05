#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node * prev;
    struct node * next;
}Node;
void addNode(int x,Node ** head,Node ** tail)
{
    Node * h = * head;
    if(h==NULL)
    {
        h = (Node *) malloc(sizeof(Node));
        h->data = x;
        h->next = NULL;
        h->prev = NULL;
        *head = h;
        *tail = h;
    }
    else
    {
        h = (Node *) malloc(sizeof(Node));
        h->data = x;
        h->next = NULL;
        h->prev = * tail;
        Node * last = * tail;
        last->next = h;
        *tail = h;
    }
}
void print(Node * head)
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
    int x;
    char c;
    Node * head1=NULL;
    Node * tail1=NULL;
    while(scanf("%d",&x))
    {
        c = getchar();
        addNode(x,&head1,&tail1);
        if(c=='\n')
            break;
    }
    Node * head2=NULL;
    Node * tail2=NULL;
    while(scanf("%d",&x))
    {
        c = getchar();
        addNode(x,&head2,&tail2);
        if(c=='\n')
            break;
    }
    Node * head=NULL;
    Node * tail=NULL;
    Node * head1_r = head1;
    Node * head2_r = head2;
    int a,b;
    while(head1_r!=NULL&&head2_r!=NULL)
    {
        a= head1_r->data;
        b= head2_r->data;
        if(a<b)
        {
            head1_r = head1_r->next;
        }
        else
        {
            head2 = head2->next;
            if(head2!=NULL)
                head2->prev = NULL;
            head1_r->prev->next = head2_r;
            head2_r->prev = head1_r->prev;
            head2_r->next = head1_r;
            head1_r->prev = head2_r;
            head2_r = head2;
        }
    }
    tail1->next = head2_r;
    print(head1);
}
