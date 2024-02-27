#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n;
	cin>>n;
	if(n==0){
		cout<<0<<" "<<0;
		return 0;
	}
	int a[n]={0},b[n]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	
	sort(a,a+n);
	if(n==1){
		cout<<a[0]<<" "<<a[0];
		return 0;
	}
	int min=0;
	for(int i=1;i<n;i++){
		
		min+=a[i-1]+a[i]-1;
		a[i]=a[i-1]+a[i];
		sort(a+i,a+n);
	}

	
	sort(b,b+n);
	int max=0;
	for(int i=n-2;i>=0;i--){

		max+=b[i]+b[i+1]-1;
		b[i]=b[i]+b[i+1];
		sort(b,b+i);
	}
	cout<<max<<" "<<min;
}
