#include<iostream>

using namespace std;

int partition(int a[],int left,int right) {
	int x=a[left];
	while(left<right) {
		while(left<right&&a[right]>=x)
			right--;
		a[left]=a[right];
		while(left<right&&a[left]<=x)
			left++;
		a[right]=a[left];
	}
	a[left]=x;
	return left;
}

int find(int a[],int left,int right,int k){
	int mid=partition(a,left,right);
	
	if(mid==k-1)
		cout<<a[mid];
		else if(mid<k-1)
			find(a,mid+1,right,k);
		else
			find(a,left,mid+1,k);
	
}

int main() {
	int n, k;
	cin>>n>>k;
	int a[n];
	for (int i=0; i<n; i++)
		cin>>a[i];
	find(a,0,n-1,k);
	return 0;
}
