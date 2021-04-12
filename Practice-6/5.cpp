// Find minimum increment/decrement
// operations to make array elements same.

#include <bits/stdc++.h>
using namespace std;

int MinOperation(vector<int>a, vector<int> b)
{
	int n=a.size();

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());


	int result = 0;


	for (int i = 0; i < n; ++i) {
		result = result + abs(a[i] - b[i]);
	}

	return result;
}


int main()
{
	int n;
	cout<<"Enter the no.of elements"<<endl;
	cin>>n;

	vector<int>a(n),b(n);

	cout<<"Enter the elements"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Enter the elements"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}

	
	cout <<"operations->"<< MinOperation(a, b)<<endl;
	return 0;
}
