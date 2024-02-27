#include<iostream>
#include<cmath>

using namespace std;

void xunhuan(int **form,int a,int r,int c){
	 if(a==1) {
        return ;
    }
    int mid=a/2;
    form[r+mid][c+mid]=form[r][c];
    form[r][c+mid]=form[r+mid][c]=form[r][c]+mid;
    xunhuan(form,mid,r,c);
    xunhuan(form,mid,r,c+mid);
    xunhuan(form,mid,r+mid,c);
    xunhuan(form,mid,r+mid,c+mid);
}



int main(){
	int n;
	cin>>n;
	int a=pow(2,n);
	int **form=new int*[a];
		for(int i=0; i<a; i++)
			form[i]=new int[a];
	for(int i=0;i<a;i++)
		form[0][i]=i+1;
	xunhuan(form,a,0,0);
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++)
			cout<<form[i][j]; 
			cout<<endl;
	}
		
} 
