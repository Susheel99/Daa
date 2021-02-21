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

int findmax_3way(int arr[],int low, int high)
{

    if (low == high){
        if(arr[low]<0)
            return 1;
        else 
            return 0;
    }


    int mid = (high - low + 1)/3;
    if(mid == 0){
        mid = 1;
    }
    int mid1 = low + mid - 1;
    int mid2 = mid1 + mid;

    int m1 = findmax_3way(arr,low, mid1);
    int m2 = findmax_3way(arr,mid1 + 1, mid2);
    int m3 = findmax_3way(arr,mid2 + 1, high);

    return m1+m2+m3;

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
	cout<<findmax_3way(arr,0,n-1)<<endl;

}