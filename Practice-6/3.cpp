//Given an array, we need to find the maximum sum of absolute difference of any permutation of the given array.

#include <bits/stdc++.h>
using namespace std;

int absSum(vector<int> a)
{
	vector<int>v;

	
	sort(a.begin(), a.end());
	int n=a.size();

	
	for (int i = 0; i < n / 2; ++i)
	 {
		v.push_back(a[i]);
		v.push_back(a[n - i - 1]);
	}

	
	if (n % 2 != 0)
		v.push_back(a[n/2]);

	
	int sum = 0;


	for (int i = 0; i < n - 1; ++i) {
		sum = sum + abs(v[i] -
								v[i + 1]);
	}

	
	sum = sum + abs(v[n - 1] - v[0]);


	return sum;
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
	cout << absSum(a) << endl;
}
