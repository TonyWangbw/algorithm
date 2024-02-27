#include<iostream>
#include<stdlib.h>
#include<string.h>
#define MAXN 1000

using namespace std;

typedef struct VNode* Vertex;
struct VNode {
	Vertex Next;
	int V;
};

typedef struct LNode {
	Vertex FirstEdge;
	
}List[MAXN];

typedef struct GNode* Graph;
struct GNode {
	int Nv,Ne;
	List Head;
};

Graph G;


void Insert(int v,int w) {
	Vertex NewNode = (Vertex)malloc(sizeof(struct VNode));
	NewNode->V = v;
	NewNode->Next = G->Head[w].FirstEdge;
	G->Head[w].FirstEdge = NewNode;
	
	NewNode = (Vertex) malloc(sizeof(struct VNode));
	NewNode->V = w;
	NewNode->Next = G->Head[v].FirstEdge;
	G->Head[v].FirstEdge = NewNode;
}

int visit[MAXN];

void BFS(int s) {
	int Q[MAXN],front = 0,rear = 0,v,i;
	int tail,last = s,cnt = 0,level = 0,kase = s;
	Vertex p;
	double perc;
	Q[++rear] = s;
	visit[s] = 1;
	cnt ++;
	while(rear!=front) {
		v = Q[++front];
		for(p = G->Head[v].FirstEdge;p;p = p->Next) {
			if(!visit[p->V]) {
				Q[++rear] = p->V;
				visit[p->V] =1;
				cnt ++;
				tail = p->V;
			}
		}
		if(v==last) {
			level ++;
			last = tail;
		}
		if(level == 6) break;
	}
	perc = ((double)cnt)/((double)G->Nv) * 100;
	printf("%d: %.2lf%%\n",kase,perc);
}
int main()
{
	int i;
	int v,w;
	G = (Graph)malloc(sizeof(struct GNode));
	cin>>G->Nv; 
	scanf("%d",&G->Ne);
	for(i=1;i<=G->Nv;i++)
		G->Head[i].FirstEdge = NULL;
	for(i=1;i<=G->Ne;i++) {
		cin>>v;
		scanf("%d",&w);
		Insert(v,w);
	}
	for(i=1;i<=G->Nv;i++) {
		memset(visit,0,sizeof(visit));
		BFS(i);
	}
	return 0;
	
}

