#include<iostream>

using namespace std;

struct Node{
	int begin;
	int end;
	int weight;
	int flag; 
}; 

int main(){
	int n,m;
	cin>>n>>m;
	Node head[m];
	
	for(int i=0;i<m;i++){
		cin>>head[i].begin;
		cin>>head[i].end;
		cin>>head[i].weight;
		head[i].flag=0;
	}
	
	for (int i = 0; i < m; i++) {
        for (int j = 0; j + 1 < m-i; j++) {
            if (head[j].weight > head[j + 1].weight) {
                Node temp;
                temp=head[j];
                head[j]=head[j+1];
                head[j+1]=temp;
            }
        }
    }
    
    for(int i=0;i<m;i++){
    	if(head[i].begin>head[i].end)
    		{
    			int t;
    			t=head[i].end;
    			head[i].end=head[i].begin;
    			head[i].begin=t;
			}
	}
    		int a[n+1];
			for(int i=1;i<n+1;i++){
			a[i]=i;
		}    
        int sum=0;
        int edge=0;
	for(int i=0;i<m;i++){
		if(a[head[i].begin]!=a[head[i].end]){
			int x=a[head[i].end];
			for(int j=1;j<n+1;j++){
				
				if(a[j]==x)
				a[j]=a[head[i].begin];
			}
			sum+=head[i].weight;
			
			/*for(int z=1;z<n+1;z++)
			cout<<a[z]<<" ";
			cout<<"\n";*/
			//cout<<sum<<"      "; 
			//head[i].flag=1;
		}
	}
	

	
	
	
	cout<<sum;
}

/*
6 10
1 2 4
1 5 1
1 6 2
2 3 6 
2 6 3
3 4 6
3 6 5
4 5 4 
4 6 5 
5 6 3 
15
*/


