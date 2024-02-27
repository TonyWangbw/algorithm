#include<iostream>

using namespace std;

int total=0;
int n=0;
int x[1000];


void backtrack(int i){
	if(i>n){
		total++;
		
	}
	for(int j=i;j<=n;j++){
		int ok = 1;
		for(int k=i;k<j;k++)
		if(x[k]==x[j]){
			ok=0;
			break;
		}
		if(ok){
			//swap(x[i],x[j]);
			int temp;
			temp=x[i];
			x[i]=x[j];
			x[j]=temp;
			backtrack(i+1);
			//swap(x[i],x[j]);
			temp=x[i];
			x[i]=x[j];
			x[j]=temp;
		}
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>x[i];
	backtrack(1);
	cout<<total;
	
}
