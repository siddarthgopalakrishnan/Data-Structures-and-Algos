#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[5000000];
typedef struct node
{
    char c;
    struct node * left;
    struct node * right;
}Node;
Node * stack[5000000];
int top=-1;
void push(Node * x)
{
        stack[++top] = x;
}
Node * pop()
{
    Node * ans = stack[top];
    top--;
    return ans;  
}
int value(Node *x)
{
    if(x->c>='0'&&x->c<='9') return (int) (x->c-'0');
    if(x->c=='/') return (value(x->left)/value(x->right));
    if(x->c=='*') return (value(x->left)*value(x->right));
    if(x->c=='+') return (value(x->left)+value(x->right));
    if(x->c=='-') return (value(x->left)-value(x->right));
}
void print(Node * x)
{
    if(x!=NULL)
    {
        if(x->c<'0'||x->c>'9')
            printf("(");
        print(x->left);
        printf("%c",x->c);
        print(x->right);
        if(x->c<'0'||x->c>'9')
            printf(")");
    }
}
int main()
{
    scanf("%s",str);
    int len = strlen(str);
    for(int i=0;i<len;i++)
    {
        Node * val = (Node *) malloc(sizeof(Node));
        val->c = str[i];
        if(str[i]>='0'&&str[i]<='9')
        {
            val->left = NULL;
            val->right = NULL;
        }
        else
        {
            Node * r = pop();
            Node * l = pop();
            val->left = l;
            val->right = r;
        }
        push(val);
    }
    Node * h = stack[0];
    printf("%d\n",value(h));
    print(h);
    printf("\n");
}