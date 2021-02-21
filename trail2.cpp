//1st question k-way
#include<bits/stdc++.h>
using namespace std;

int arr[10]={1,2,3,4,9,8,7,0};

int findmax_kway(int low, int high, int k)
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

    int m1 = findmax_kway(low, mids[0], k);
    int maxi = m1;

    for(int i=0; i<k-1; i++){

        int m2 = findmax_kway(mids[i] + 1, mids[i+1], k);
        if(maxi<m2){
            maxi = m2;
        }
    }


    int m3 = findmax_kway(mids[k-2] + 1, high, k);

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
	cout<<findmax_kway(0,9,5)<<endl;
}