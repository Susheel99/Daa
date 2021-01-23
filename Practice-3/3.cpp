#include<bits/stdc++.h>
using namespace std;

#define ll long long

void subsetsum(vector<int>v,int n, int k)
{
	ll sz=1<<(v.size()-1);

	for(int i=1;i<=sz;i++)
	{
		ll sum=0;
		for(int j=0;j<v.size();j++)
		{
			if(i&(1<<j))
			{
				sum=sum+v[j];
			}
		}
		if(sum==k){
			cout<<"Yes"<<endl;
			return ;
		}
	}
	cout<<"No"<<endl;
}


int main()
{
	int n;
	cin>>n;
	vector<int>v(n);

	for(int i=0;i<n;i++)
		cin>>v[i];

	int k;
	cin>>k;

	subsetsum(v,n,k);

}