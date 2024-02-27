#include<iostream>

int n;
int a[100][100];
int mini=9999;
int vis[100];

using namespace std;


void dfs(int number,int sum,int now){
    if(number==n)
    {
        sum+=a[now][1];
        if(sum<mini)
            mini=sum;
        return;
    }
    for(int i=1;i<n+1;i++)
    {
        if(vis[i]==0&&a[now][i]!=0)
        {
            vis[i]=1;
            dfs(number+1,sum+a[now][i],i);
            vis[i]=0;
        }
    }
}
int main(){
    cin>>n;
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			cin>>a[i][j];
		}
	}
    vis[1]=1;
    dfs(1,0,1);
    cout<<mini;
    return 0;
}
