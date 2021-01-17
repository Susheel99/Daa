#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	map<int,int>m;
	m['a']=max(5,6);
	m['b']=max(10,9);
	for(auto it=m.begin();it!=m.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
}