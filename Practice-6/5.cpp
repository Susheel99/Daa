// CPP program to find minimum increment/decrement
// operations to make array elements same.

#include <bits/stdc++.h>
using namespace std;

int MinOperation(vector<int>a, vector<int> b)
{
	int n=a.size();
	// sorting both arrays in
	// ascending order
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	// variable to store the
	// final result
	int result = 0;

	// After sorting both arrays
	// Now each array is in non-
	// decreasing order. Thus,
	// we will now compare each
	// element of the array and
	// do the increment or decrement
	// operation depending upon the
	// value of array b[].
	for (int i = 0; i < n; ++i) {
		result = result + abs(a[i] - b[i]);
	}

	return result;
}

// Driver code
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
