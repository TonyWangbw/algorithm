#include<iostream>

using namespace std;

int  dp[1000][1000];

int main(){
	int n,m;
	cin>>n>>m;
	int v[n+1],w[m+1];
	for(int i=1;i<n+1;i++){
		cin>>v[i];
		cin>>w[i];
	}
	for(int i=1;i<n+1;i++){
    for(int j=0;j<=m;j++){
        if(j<v[i])
            dp[i][j] = dp[i-1][j];
        else
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
    }
}
	cout<<dp[n][m];

} 


