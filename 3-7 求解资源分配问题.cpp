#include<iostream>

using namespace std;

int  dp[1000][1000];

int main(){
	int n,m;
	cin>>n>>m;
	int a[n+1][m+1];
	int b[n+1][m+1];
	for(int i=0;i<n+1;i++){
    for(int j=0;j<m+1;j++){
        cin>>a[i][j];
        b[i][j]=0;
    }
}


for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            for (int k=1;k<=j;++k) {
                int sum = dp[i - 1][j - k] + a[i][k];
                if (sum >= dp[i][j]) {
                    dp[i][j]=sum;
                    b[i][j]=k;
                }
            }
        }
    }

		
	int max1=0;
	int z,t;
	int k=1;
	int p=1;
	for(k=0;k<m+1;k++){
		for(p=0;p<m+1;p++){
			if(max1<dp[k][p]){
				max1=dp[k][p];
				z=k;
				t=p;
			}
				
		//	max1=max(max1,dp[k][p]);
		}
	}		
		for (int i = n; i > 0; --i) {
        cout << i << " " << b[i][m] << endl;
   
        m -= b[i][m];
    }
    cout << max1;

}

/*
3 5
0 0 0 0 0 0
0 3 7 9 12 13
0 5 10 11 11 11
0 4 6 11 12 12
*/
