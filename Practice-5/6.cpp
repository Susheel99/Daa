#include<bits/stdc++.h>
using namespace std;

void insert(vector<int>v,int n)
{
	int i,temp;
	i=n;temp=v[i];
	while(i>1 && temp>v[i/2])
	{
		v[i]=v[i/2];
		i=i/2;
	}
	v[i]=temp;

	for(int i=1;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	cout<<"Enter the number of elements"<<endl;
	int n;
	cin>>n;

	vector<int>a(n);
	cout<<"Enter the elements"<<endl;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}

	vector<int>v;
	v.push_back(-1);
	for(int i=1;i<=n;i++)
	{
		v.push_back(a[i]);
	    insert(v,v.size()-1);
	}
	

}