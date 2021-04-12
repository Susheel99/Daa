//Minimum sum of two numbers formed from digits of an array

#include <bits/stdc++.h>
using namespace std;


int solve(vector<int>v)
{
	sort(v.begin(), v.end());

	int a = 0, b = 0;
	for (int i = 0; i < n; i++)
	{
		if (i & 1)
			a = a*10 + v[i];
		else
			b = b*10 + v[i];
	}


	return a + b;
}

int main()
{
	int n;
	cout<<"Enter the no.of elements"<<endl;
	cin>>n;

	vector<int>a(n);

	cout<<"Enter the elements"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout << solve(a) << endl;
}
