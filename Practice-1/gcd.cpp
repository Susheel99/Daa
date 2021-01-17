#include<bits/stdc++.h>
using namespace std;

int main()
{
	
		int a,b;
		cin>>a>>b;
		int ans=-1;
		for(int i=1;i<=min(a,b);i++)
		{
			if(a%i==0 and b%i==0)
				ans=i;
		}
		cout<<"Gcd of "<<a<<" and "<<b<<" is "<<ans<<endl;
	
}