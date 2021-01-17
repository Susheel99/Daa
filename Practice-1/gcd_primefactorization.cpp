#include<bits/stdc++.h>
using namespace std;

#define ll long long

//Fast exponentiation.
ll power(int n,int p)
{
	if(p==0)
		return 1;

	ll subprob=power(n,p/2);

	if(p&1)
		return n*subprob*subprob;

	return subprob*subprob;
}

map<int,int> prime_factorization(int n)
{
	map<int,int>m;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			while(n%i==0)
			{
				n=n/i;
				m[i]++;
			}
		}
	}
	if(n!=1)
	{
		m[n]++;
	}
	return m;
}

int main()
{
		map<int,int>m1,m2,m3;
		int a,b;
		cout<<"Enter two numbers to compute gcd"<<endl;
		cin>>a>>b;
		m1=prime_factorization(a);
		m2=prime_factorization(b);
		// for(auto it=m1.begin();it!=m1.end();it++)
		// {
		// 	cout<<it->first<<" "<<it->second<<endl;
		// }

		for(auto it=m1.begin();it!=m1.end();it++)
		{
			m3[it->first]=min(it->second,m2[it->first]);
		}

		ll res=1;
		for(auto it=m3.begin();it!=m3.end();it++)
		{
			res=res*power(it->first,it->second);
		}
		cout<<"GCD is-"<<res<<endl;
		

	
}