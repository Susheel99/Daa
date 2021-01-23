#include<bits/stdc++.h>
using namespace std;

void method1(vector<int>v,int n)
{
	cout<<"Method1"<<endl;
	set<int>s;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(v[i]==v[j])
				s.insert(v[i]);
		}
	}
	for(auto it=s.begin();it!=s.end();it++)
		cout<<*it<<endl;
}

void method2(vector<int>v,int n)
{
	cout<<"Method2"<<endl;
	map<int,int>m;
	for(int i=0;i<n;i++)
	{
		m[v[i]]++;
	}
	for(auto it=m.begin();it!=m.end();it++)
	{
		if(it->second>1)
			cout<<it->first<<endl;
	}
}

int main()
{
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	method1(v,n);
	method2(v,n);
}