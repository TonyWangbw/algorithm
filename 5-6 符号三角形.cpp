#include<iostream>

using namespace std;

int n;
int half;
int sum; 
int count; 
int p[100][100];

void Dfs(int t)
{
		if(t == n && count == half)
		{
			sum ++;
			return ; 
		} 
		for(int i = 0; i < 2; i++) 
		{
			p[0][t] = i;
			count += i; 
			for(int j = 1; j <= t; j++)
			{
				p[j][t-j] = p[j-1][t-j]^p[j-1][t-j+1];
				count += p[j][t-j];
			}
			if(count <= half && (t+2)*(t+1)/2 - count <= half)
			{
				Dfs(t + 1); 
			} 
			for( int j = 1; j <= t; j++)
			{
				count -= p[j][t-j];
			} 
			count -= i;
		}
}	

int main()
{
	cin>>n;
	half = (n+1) * n / 4; 
	sum = 0; 
	count = 0; 
	Dfs(0);
	cout<<sum<<endl;
	
	return 0;
}
