#include<iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	int b=2;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b*=2;
	}
	
	cout<<b/2;
}
