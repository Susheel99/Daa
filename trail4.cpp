//2st question 3-way
#include<bits/stdc++.h>
using namespace std;

int arr[9]={2,-1,4,-5,3,-9,-8,7,6};

int findmax_3way(int low, int high)
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

    int m1 = findmax_3way(low, mid1);
    int m2 = findmax_3way(mid1 + 1, mid2);
    int m3 = findmax_3way(mid2 + 1, high);

    return m1+m2+m3;

}

int main()
{
	cout<<findmax_3way(0,8)<<endl;
}