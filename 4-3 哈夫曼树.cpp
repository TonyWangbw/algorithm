#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
using namespace std;
struct node{
	char c;//�ַ� 
	int hz;//Ƶ�� 
	int p;//���ȼ� 
	node* left;
	node* right;
};
struct cmp{//�Ȱ��ַ����ֵ�Ƶ�ʴ�С�������У������ͬ�Ͱ����ȼ���С�������� 
	bool operator()(const node*a,const node*b){
		if(a->hz!=b->hz)
		return a->hz>b->hz;
		else
		return a->p>b->p;
	}
};
string x,y,z;
int idx,sum;//idx�����������ȼ���sum��¼ԭ�����������ܳ��� 
map<char,int>mp,np;//mp��¼�ַ����ֵ�Ƶ�ʣ�np��¼�ַ������ȼ� 
vector<char>ma;//�������� 
priority_queue<node*,vector<node*>,cmp>q,r;//q���ڹ������������r���ڰ��ַ����ֵ�˳��������� 
map<char,vector<int> >cp;//��¼ÿ���ַ��ı��� 
vector<int>v;//����������������ÿ���ַ��ı��� 
void dfs(node* root)//Ϊÿ���ַ����б��� 
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
void translation(string x)//���뺯�� 
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
	for(int i=0;i<x.size();i++)//ͳ���ַ����ֵ�Ƶ�ʺ����ȼ� 
	{
		char temp=x[i];
		mp[temp]++;
		if(!np[temp])
		np[temp]=idx++;
	}
	for(auto temp:mp)//��װ�ڵ� 
	{
		node* t=new node;
		t->c=temp.first;
		t->hz=temp.second;
		t->p=np[temp.first];
		t->left=t->right=NULL;
		q.push(t);
		r.push(t);
	}
	while(q.size()!=1)//����������� 
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
