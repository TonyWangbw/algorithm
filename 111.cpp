	#include<iostream>
	#include<stdlib.h>
	using namespace std;
	
	int match_insertion(int a[],int n,int b[],int z){
		int flag=0;
		for(int i=0;i<n;i++){
			if(a[i]!=b[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==0){
			cout<<"Insertion Sort"<<endl;
		z++;
			for(int j=0;j<z;j++){
				if(a[z]<a[j]){
					int m=a[z];
					for(int k=z;k>j;k--){
						a[k]=a[k-1];
					}
					a[j]=m;
				}
			}
			for(int i=0;i<n;i++){
				if(i!=n-1)
					cout<<a[i]<<" ";
					else
					cout<<a[i]<<endl;
			}
			exit(0);
				return 1;
		}
			return 0;
	}
	
	void Insertion_Sort(int a[],int n,int b[]){
		int z;
		
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				if(a[i]<a[j]){
					int m=a[i];
					for(int k=i;k>j;k--){
						a[k]=a[k-1];
					}
					a[j]=m;
				}
				if(match_insertion(a,n,b,i))
					return;
				
			}
		}
	}
	
	int match_merge(int *a,int len,int seg,int b[]){
			int flag=0;
		for(int i=0;i<len;i++){
			if(a[i]!=b[i])
			{
				flag=1;
				break;
			}
		}
		
		if(flag==0){
			cout<<"Merge Sort"<<endl;
			
			for (int start = 0; start < len; start += seg + seg) {
	            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
	            int k = low;
	            int start1 = low, end1 = mid;
	            int start2 = mid, end2 = high;
	            while (start1 < end1 && start2 < end2)
	                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
	            while (start1 < end1)
	                b[k++] = a[start1++];
	            while (start2 < end2)
	                b[k++] = a[start2++];
	        }
	        int* temp = a;
	        a = b;
	        b = temp;
	    
	    	for(int i=0;i<len;i++){
	    		if(i!=len-1)
	    			cout<<a[i]<<" ";
	    			else 
	    			cout<<a[i]<<endl;
			}
			
				
			return 1;
		}
			return 0;
	}
	
	int min(int x, int y) {
	    return x < y ? x : y;
	}
	
	void merge_sort(int arr[],int c[],int len) {
		
	    int* a = arr;
	    if(match_merge(a,len,1,c)==1){
	    		return;
			}
	    int* b = (int*) malloc(len * sizeof(int));
	    int seg, start;
	    for (seg = 1; seg < len; seg += seg) {
	        for (start = 0; start < len; start += seg + seg) {
	            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
	            int k = low;
	            int start1 = low, end1 = mid;
	            int start2 = mid, end2 = high;
	            while (start1 < end1 && start2 < end2)
	                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
	            while (start1 < end1)
	                b[k++] = a[start1++];
	            while (start2 < end2)
	                b[k++] = a[start2++];
	        }
	    	if(match_merge(a,len,seg,c)==1){
	    		return;
			}
	        int* temp = a;
	        a = b;
	        b = temp;
	    }
	 
				
	    if (a != arr) {
	        int i;
	        for (i = 0; i < len; i++)
	            b[i] = a[i];
	        b = a;
	    }
	    free(b);
	}
	 
	int main(){
		int n;
		cin>>n;
		int a[n],b[n],c[n];	
		for(int i=0;i<n;i++){
			cin>>a[i];
			c[i]=a[i];
		}
			
		for(int i=0;i<n;i++)
			cin>>b[i];
		Insertion_Sort(a,n,b);
		merge_sort(c,b,n);
		
		return 0;
	}
	
	/*
	10
	3 1 2 8 7 5 9 4 6 0
	1 2 3 7 8 5 9 4 6 0
	*/
