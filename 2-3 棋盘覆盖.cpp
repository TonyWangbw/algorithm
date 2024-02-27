#include<iostream>
#include<cmath>

using namespace std;

int N=0;

void fugai(int **form,int a,int b,int c,int d,int size){//c和d是本来就存在的点 
	if(size==1)
		return ;
	N++;
	int n=N;
	int s=size/2;
	if(c<a+s&&d<b+s)
		fugai(form,a,b,c,d,s);
	else{
		form[a+s-1][b+s-1]=n;
		fugai(form,a,b,a+s-1,b+s-1,s);
	}
	
	if(c<a+s&&d>=b+s)
		fugai(form,a,b+s,c,d,s);
	else{
		form[a+s-1][b+s]=n;
		fugai(form,a,b+s,a+s-1,b+s,s);
	}
	
	if(c>=a+s&&d>=b+s)
		fugai(form,a+s,b+s,c,d,s);
	else{
		form[a+s][b+s]=n;
		fugai(form,a+s,b+s,a+s,b+s,s);
	}
	
	if(c>=a+s&&d<b+s)
		fugai(form,a+s,b,c,d,s);
	else{
		form[a+s][b+s-1]=n;
		fugai(form,a+s,b,a+s,b+s-1,s);
	}
}

int main(){
	int a,b;
	cin>>a>>b;
	a=a-1;
	b=b-1;
	int n;
	cin>>n;
	int **form=new int*[n];
		for(int i=0; i<n; i++)
			form[i]=new int[n]; 
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		form[i][j]=0;
	form[a][b]=0;
	fugai(form,0,0,a,b,n);	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<"   "<<form[i][j]; 
		}
			if(i!=n-1)
			cout<<endl;
	}		
} 
