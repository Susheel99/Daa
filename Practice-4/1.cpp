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

int findmax_3way(int arr[],int low, int high)
{

    if (low == high){
        return arr[low];
    }

    if(low>high){
        return -9999;
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

    if(m1>m2){
        if(m1>m3){
            return m1;
        }
        else{
            return m3;
        }
    }
    else{
        if(m2>m3){
           return m2;
        }
        else{
            return m3;
        }
    }
}

int findmax_kway(int arr[],int low, int high, int k)
{

    if (low == high){
      return arr[low];
    }

    if(low>high){
        return -9999;
    }

    int mids[k];
    int mid = (high - low + 1)/k;
    if(mid == 0){
        mid = 1;
    }
    mids[0] = low + mid - 1;
    for(int i = 1; i<k; i++){
        if(i>(high - low)){
            mids[i] = mids[0];
        }
        else{
            mids[i] = mids[i-1] + mid;
        }

    }

    int m1 = findmax_kway(arr,low, mids[0], k);
    int maxi = m1;

    for(int i=0; i<k-1; i++){

        int m2 = findmax_kway(arr,mids[i] + 1, mids[i+1], k);
        if(maxi<m2){
            maxi = m2;
        }
    }


    int m3 = findmax_kway(arr,mids[k-2] + 1, high, k);

    if(m3>maxi){

        // cout<<m3<<"\n";
        return m3;
    }
    else{
        // cout<<maxi<<"\n";
        return maxi;
    }
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
	cout<<"3-way "<<findmax_3way(arr,0,n-1)<<endl;
	cout<<"k-way "<<findmax_kway(arr,0,n-1,4)<<endl;
}