#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
	if(b==0)
		return a;

	return gcd(b,a%b);
}

int main()
{
	int n;
	cout<<"Enter the no.of test cases"<<endl;
	cin>>n;
	while(n--)
	{
		int a,b;
		cout<<"Enter two numbers"<<endl;
		cin>>a>>b;
		cout<<gcd(a,b)<<endl;
	}

}