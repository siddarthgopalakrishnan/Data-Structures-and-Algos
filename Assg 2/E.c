#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

int stack[MAX];
int b=-1,t=-1,v;
int adj[MAX][MAX];
int status[MAX];

void clearStatus(){
	for(int i=0;i<v;i++)
		status[i]=initial;
}

void push(int x){
	//printf("%d\n",t);
	if(t==MAX-1)
		printf("stack overflow");
	else
		{
			if(b==-1)
				b=0;
			t++;
			stack[t]=x;
		}
}

int pop(){
int y;
	if(b>t || b==-1)
		exit(0);
	else
	{
		y=stack[t];
		t--;
	}
	return y;
}

int empty(){
	if(b>t  ||  b==-1)
		return 1;
	else
		return 0;
}

int dfs(int u){
	push(u);
	status[u]=waiting;
	int count = 0;
	while(!empty()){
		
		int w=pop();
		count++;
		status[w]=visited;
		
		int i;
		for(i=0;i<v;i++){
			if(adj[w][i]==1 && status[i]==initial){
				push(i);
				status[i]=waiting;
			}
		}
	}
	if(count==v)	//All nodes are reachable
		return 1;
	else
		return 0;
}

int main(){
	int e;
	scanf("%d %d",&v,&e);
	int i,j;
	for(i=0;i<e;i++){
		for(j=0;j<e;j++)
			adj[i][j]=0;
	}
	for(j=0;j<e;j++){
		int from,to;
		scanf("%d %d",&from,&to);
		adj[from][to]=1;
	}
	int flag = 0,ans;
	for(i=1;i<=v;i++){
		clearStatus();
		if(dfs(i)){
			flag = 1;
			ans =  v;
			break;
		}
	}
	if(flag==1)
		printf("%d",ans);
	else
		printf("BAD LUCK");
	return 0;
}