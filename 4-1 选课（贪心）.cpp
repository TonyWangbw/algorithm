#include<iostream>

using namespace std;

struct Node{
	string Cname;
	float a;
	float b;
};

int main(){
	int n;
	cin>>n;
	Node head[n];
	for(int i=0;i<n;i++){
		cin>>head[i].Cname;
		cin>>head[i].a;
		cin>>head[i].b;
	}

    Node temp;
    for (int i = 0; i < n - 1; i++){
    	for (int j = 0; j < n - 1 - i; j++){
    		if (head[j].b < head[j+1].b) {
                temp = head[j];
                head[j] = head[j + 1];
                head[j + 1] = temp;
                        }
		}        
	}
	
/*	for(int i=0;i<n;i++){
		cout<<head[i].b<<" ";
	}*/
	
	float time=24;
	int flag=0;
	for(int i=0;i<n;i++){
		if(head[i].b<=time){
			flag++;
			time=head[i].a;
		}
		
	}
	cout<<flag;
        
}
