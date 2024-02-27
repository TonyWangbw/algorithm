#include<iostream>
#include<string.h>
using namespace std;
typedef struct {
	int row;
	int col;
} Position;
int row,col,start_row,start_col,sum,a[20][20];
Position p[8];
void backtrack(int m,int n,int i)
{
	if(row*col==i)
		sum++;
	else
		for(int j=0; j<8; j++) {
			if(!a[m+p[j].row][n+p[j].col]&&m+p[j].row<row&&m+p[j].row>=0&&n+p[j].col<col&&n+p[j].col>=0) {
				a[m+p[j].row][n+p[j].col]=1;
				backtrack(m+p[j].row,n+p[j].col,i+1);
				a[m+p[j].row][n+p[j].col]=0;
			}
		}
}
int main()
{
	p[0].row=-2;
	p[0].col=1;
	p[1].row=-1;
	p[1].col=2;
	p[2].row=1;
	p[2].col=2;
	p[3].row=2;
	p[3].col=1;
	p[4].row=2;
	p[4].col=-1;
	p[5].row=1;
	p[5].col=-2;
	p[6].row=-1;
	p[6].col=-2;
	p[7].row=-2;
	p[7].col=-1;
	int k;
	cin>>k;
	for(int i=1; i<=k; i++) {
		memset(a,0,sizeof(a));
		sum=0;
		cin>>row>>col>>start_row>>start_col;
		a[start_row][start_col]=1;
		backtrack(start_row,start_col,1);
		cout<<sum<<endl;
	}
}
