#include <iostream>
 
using namespace std;

int cost[100][100];
int m[100];
 
int main()
{
    int n,i,j;
    cin>>n; 
        for(i=1;i<n;i++)
            for(j=i+1;j<=n;j++)
                cin>>cost[i][j];
        m[1]=0;
        int min;
        for(i=2;i<=n;i++)
        {
            min=cost[1][i];
            for(j=1;j<=i-1;j++)
            {
                if(cost[j][i]!=0 && m[j]+cost[j][i]<min)
                    min=m[j]+cost[j][i];
            }
            m[i]=min;
        }
        cout<<m[n]<<endl;
    return 0;
}
