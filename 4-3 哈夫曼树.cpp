#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
using namespace std;
struct node{
	char c;//字符 
	int hz;//频率 
	int p;//优先级 
	node* left;
	node* right;
};
struct cmp{//先按字符出现的频率从小到大排列，如果相同就按优先级从小到大排列 
	bool operator()(const node*a,const node*b){
		if(a->hz!=b->hz)
		return a->hz>b->hz;
		else
		return a->p>b->p;
	}
};
string x,y,z;
int idx,sum;//idx用于设置优先级，sum记录原序列译码后的总长度 
map<char,int>mp,np;//mp记录字符出现的频率，np记录字符的优先级 
vector<char>ma;//用于译码 
priority_queue<node*,vector<node*>,cmp>q,r;//q用于构造哈夫曼树，r用于按字符出现的顺序输出编码 
map<char,vector<int> >cp;//记录每个字符的编码 
vector<int>v;//遍历哈夫曼树生成每个字符的编码 
void dfs(node* root)//为每个字符进行编码 
{
	if(root)
	{
		if(islower(root->c))
		cp[root->c]=v;
		v.push_back(0);
		dfs(root->left);
		v.pop_back();
		v.push_back(1);
		dfs(root->right);
		v.pop_back();
	}
}
void translation(string x)//译码函数 
{
	ma.clear();
	node* t=new node;
	t=q.top();
	bool flag=true;
	for(int i=0;i<x.size();i++)
	{
		if(x[i]=='0')
		t=t->left;
		else
		t=t->right;
		if((i==(x.size()-1))&&isupper(t->c))
		flag=false;
		if(islower(t->c))
		{
			ma.push_back(t->c);
			t=q.top();
		}
	}
	if(flag)
	for(auto t:ma)
	cout<<t;
	else
	cout<<"INVALID";
	cout<<endl;
}
int main()
{
	cin>>x>>y>>z;
	for(int i=0;i<x.size();i++)//统计字符出现的频率和优先级 
	{
		char temp=x[i];
		mp[temp]++;
		if(!np[temp])
		np[temp]=idx++;
	}
	for(auto temp:mp)//包装节点 
	{
		node* t=new node;
		t->c=temp.first;
		t->hz=temp.second;
		t->p=np[temp.first];
		t->left=t->right=NULL;
		q.push(t);
		r.push(t);
	}
	while(q.size()!=1)//构造哈夫曼树 
	{
		node* a=new node;
		a=q.top();
		q.pop();
		node* b=new node;
		b=q.top();
		q.pop();
		node* t=new node;
		t->c='S';
		t->p=idx++;
		t->hz=a->hz+b->hz;
		t->left=a;
		t->right=b;
		q.push(t);
		sum+=t->hz;
	}
	cout<<x.size()<<" ";
	int cnt=sum/8;
	if(cnt*8<sum)
	cnt++;
	cout<<cnt<<endl;
	dfs(q.top());
	while(r.size())
	{
		char t=r.top()->c;
		cout<<t<<":";
		for(auto temp:cp[t])
		cout<<temp;
		cout<<endl;
		r.pop();
	}
	translation(y);
	translation(z);
	return 0;
}

//
