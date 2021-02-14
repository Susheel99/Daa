#include<bits/stdc++.h>
using namespace std;

int way1(int *arr,int n)
{
	int m=arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]>m)
		{
			m=arr[i];
		}
	}
	return m;
}

int way2(int *arr,int s,int e)
{
	if(s==e)
		return arr[s];

	int mid=(s+e)/2;
	int a=way2(arr,s,mid);
	int b=way2(arr,mid+1,e);

	return max(a,b);
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"1-Way "<<way1(arr,n)<<endl;
	cout<<way2(arr,0,n-1)<<endl;
}