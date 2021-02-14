#include<bits/stdc++.h>
using namespace std;

int way2(int *arr,int s,int e)
{
	if(s==e)
	{
		if(arr[s]<0)
			return 1;
		else if(arr[s]>0)
			return 0;
	}
	int mid=(s+e)/2;
	return way2(arr,s,mid)+way2(arr,mid+1,e);
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
	cout<<way2(arr,0,n-1)<<endl;

}