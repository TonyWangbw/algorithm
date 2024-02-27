#include<iostream>

using namespace std;

	int a[1000][1000];
	int b[1000][1000];
	
int main(){
	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=0;
			b[i][j]=0;
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<i+1;j++) 
		cin>>a[i][j];
		
/*	for(int i=0;i<n;i++){
		for(int j=0;j<i+1;j++) {
			if(j!=i)
			cout<<a[i][j]<<" ";	
			else 
			cout<<a[j][j]<<endl;	
		}

	}*/
	
	for(int j=0;j<n;j++)
		b[n-1][j]=a[n-1][j];
		
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<=i;j++){
			b[i][j]=max(b[i+1][j],b[i+1][j+1])+a[i][j];
		}
	}
	
	cout<<b[0][0];	
	return 0;
} 
