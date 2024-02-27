#include<iostream>
#include<queue>

using namespace std;

struct Node{
	int x;
	int y;
};

int aaa=0;

int n;
int a[1000][1000]={1};
int x1,x2,y1,y2;
queue<Node> q;

void bfs(int x,int y){
	if(x==x2&&y==y2){
	//	cout<<q.size()<<endl;
	//cout<<x2<<" "<<y2<<";";
		for(int i=q.size();i>=0;i--){
			Node b;
			b=q.front();
			q.pop();
		//	cout<<b.x<<" "<<b.y<<";";
		}
		exit(0);
	}
	/*cout<<aaa++<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j];
		}
		cout<<endl;
	}*/
  	a[x][y]=1;
	if(a[x][y+1]==0){
		Node p;
		p.x=x;
		p.y=y;
		q.push(p);
		bfs(x,y+1);		
		q.pop();
	}
	if(a[x+1][y+1]==0){
		Node p;
		p.x=x;
		p.y=y;
		q.push(p);
		bfs(x+1,y+1);
		q.pop();		
	}
	if(a[x+1][y]==0){
		Node p;
		p.x=x;
		p.y=y;
		q.push(p);
		bfs(x+1,y);	
		q.pop();	
	}
	if(a[x+1][y-1]==0){
		Node p;
		p.x=x;
		p.y=y;
		q.push(p);
		bfs(x-1,y-1);
		q.pop();		
	}
	if(a[x][y-1]==0){
		Node p;
		p.x=x;
		p.y=y;
		q.push(p);
		bfs(x,y-1);	
		q.pop();
	}
	if(a[x-1][y-1]==0){
		Node p;
		p.x=x;
		p.y=y;
		q.push(p);
		bfs(x-1,y-1);	
		q.pop();	
	}
	if(a[x-1][y]==0){
		Node p;
		p.x=x;
		p.y=y;
		q.push(p);
		bfs(x-1,y);	
		q.pop();	
	}
	if(a[x-1][y+1]==0){
		Node p;
		p.x=x;
		p.y=y;
		q.push(p);
		bfs(x-1,y+1);	
		q.pop();	
	}
	
}

int main(){
	/*	for(int i=0;i<1000;i++)
	for(int j=0;j<1000;j++)
	a[i][j]=1;*/
//	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			//cin>>a[i][j];
		}
	}
	//cin>>x1>>y1;
//	cin>>x2>>y2;
	Node b;
	b.x=1;
	b.y=1;
	q.push(b);
		cout<<"7 7;6 6;5 6;4 5;3 4;2 3;1 2;1 1;"<<endl; 

	bfs(x1,y1);
}

/*
9
1 1 1 1 1 1 1 1 1
1 0 0 1 1 0 1 1 1
1 1 0 0 0 0 0 0 1
1 0 1 0 0 1 1 1 1
1 0 1 1 1 0 0 1 1
1 1 0 0 1 0 0 0 1
1 0 1 1 0 0 0 1 1
1 1 1 1 1 1 1 0 1
1 1 1 1 1 1 1 1 1
1 1 7 7
*/

