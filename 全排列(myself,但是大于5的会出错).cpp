#include<iostream>

int N; 

using namespace std;

void Delete(int *a,int m,int n){
	int b=a[m];
	for(int i=m;i<n-1;i++)
		a[i]=a[i+1];
	a[n-1]=b;
}
 
void paixu(int *a,int n)
{
	for() 
	if(n<2){
		for(int z=0;z<N;z++){
			cout<<a[z]<<" ";
		}
		cout<<endl;
	}
	else{
		for(int i=n-1;i>=0;i--)
	{
		int b[n+1];
		for(int k=0;k<N;k++)				
			b[k]=a[k];							
		Delete(b,i,n);
		paixu(b,n-1);		
	}
	}
}

int main()
{
	int n;
	cin>>n;
	int a[n+1];
	N=n;
	int i;
	for(i=0;i<n+1;i++)
		a[i]=i+1;
	a[n]=n;
	paixu(a,n);
	return 0;
}
