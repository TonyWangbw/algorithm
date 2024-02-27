#include<iostream>

int N;

using namespace std;

void swap(int &a , int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
 } 

void Perm(int list[] , int k ,int m) 
{
	if(k==m)
	{
		for(int i=0 ;i<m ;i++)
		 cout<<list[i];
		 cout<<endl; 
	 } 
	 else{
	 	for(int i=k;i<m;i++)
	 	{
	 		swap(list[i],list[k]);
	 		Perm(list,k+1,m);
	 		swap(list[i] , list[k]);
		 }
	 }
	 
}

 int main()
{
	int n;
	cin>>n;
	int a[n];
	N=n;
	int i;
	for(i=0;i<n;i++)
		a[i]=i+1;
	Perm(a,0,n);
	return 0;
}

