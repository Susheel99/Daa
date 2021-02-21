//1st question 2-way
#include<bits/stdc++.h>
using namespace std;

int arr[]={2,3,100,99,5};

int findmax_2way(int low, int high)
{
    if (low == high)
    {
        return arr[low];
    }

    int mid = (low + high) / 2;

    int m1 = findmax_2way(low, mid);

    int m2 = findmax_2way(mid + 1, high);

    if(m1>m2){
        return m1;
    }
    else{
        return m2;
    }
}

int main()
{
	cout<<findmax_2way(0,4)<<endl;
}