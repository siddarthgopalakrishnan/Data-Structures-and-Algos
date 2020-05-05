#include<stdio.h>
#define MAX 10000
#define initial 1
#define waiting 2
#define visited 3

int queue[MAX];
int adj[MAX][MAX];
int status[MAX];
int level [MAX];
int r=-1,f=-1;

void enqueue(int x){
	if(r==MAX-1){
		printf("queue overflow\n");
	}
	else
	{
	if(f==-1)
		f=0;
	r=r+1;
	queue[r]=x;
	}
	
}

int dequeue(){
	if(f==-1 || f>r)
		printf("empty\n");
	int y=queue[f];
	f=f+1;
	return y;
	
}

int empty(){
	if(f==-1 || f>r)
		return 1;
	else
		return 0;
}

void bfs(int v,int w){
	
	enqueue(w);
	status[w]=waiting;

	while(!empty()){
		int u=dequeue();
		status[u]=visited;
		int j;
		for(j=0;j<v;j++){
			if(adj[u][j]==1 && status[j]==initial){
				
				enqueue(j);
				status[j]=waiting;
				level[j]=level[u]+1;
			}
		}
	}
}
int main(){
	int v,e;
	scanf("%d",&v);
    int i,j;
	for(i=0;i<MAX;i++)
		status[i]=initial;
	e=v-1;	
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			adj[i][j]=0;
		
		}
	level[i]=-1;
	}
	
	for(i=1;i<=e;i++){
		int parent;
		scanf("%d",&parent);
		adj[i][parent]=1;adj[parent][i]=1;
	}
	level[0]=0;
	bfs(v,0);
	int lv,cnt=0;
	scanf("%d",&lv);
	int flag = 0;
		for(j=0;j<v;j++)
		{
			if(level[j]==lv){
				flag++;
				cnt++;
				printf(" %d ",j);	
			}
		}
	if(flag==0)
		printf("-1");
	else
		printf("\n%d",cnt);
	return 0;
}
