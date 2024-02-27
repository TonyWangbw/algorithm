#include <iostream>

using namespace std;
 
int w[100];
int v[100];
int x[100];
int n,c;
 
int cw=0;
int cv=0;
 
int bestp=0;
int bestx[100];//记录是否被选 
 
void backtrack(int k)
{
   if(k>n){
     if(cv>bestp){
        bestp = cv;
        for(int i=1; i<=n; i++)
            bestx[i] = x[i];
        }
    }
   else{
     for(int i=0; i<=1; i++){
        x[k]=i;
        if(i==0){
            backtrack(k+1);
        }
        else{
           if((cw+w[k])<=c){
             cw += w[k];
             cv += v[k];
             backtrack(k+1);
             cw -= w[k];
             cv -= v[k];
           }
        }
     }
  }
}
 
int main()
{
	int flag=0;
    cin>>n;
	cin>>c;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>v[i];
    }
    backtrack(1);
	for(int i=1;i<=n;i++){
    	if(bestx[i])
    	cout<<i<<" ";
    	flag=1;
	}
	if(bestp)
	cout<<endl;
	if(!bestp)
	cout<<"No"<<endl;
    cout<<bestp<<endl;
    
    return 0;
}
