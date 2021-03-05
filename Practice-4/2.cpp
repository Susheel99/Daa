#include<bits/stdc++.h>
using namespace std;

class Parent{
public:
	int n;
	vector<int>arr;
	void input(int N)
	{
		n=N;
		for(int i=0;i<n;i++)
		{
			int x;cin>>x;
			arr.push_back(x);
		}
	}
};

class Child: public Parent{
public:
	int find_2way(int s,int e);
	int find_3way(int s,int e);
	
};

int Child::find_2way(int s,int e)
{
	if(s==e)
	{
		if(arr[s]<0)
			return 1;
		else if(arr[s]>0)
			return 0;
	}
	int mid=(s+e)/2;
	return find_2way(s,mid)+find_2way(mid+1,e);
}

int Child::find_3way(int low, int high)
{

    if (low == high){
        if(arr[low]<0)
            return 1;
        else 
            return 0;
    }
    if(low>high)
    	return 0;


    int mid = (high - low + 1)/3;
    if(mid == 0){
        mid = 1;
    }
    int mid1 = low + mid - 1;
    int mid2 = mid1 + mid;

    int m1 = find_3way(low, mid1);
    int m2 = find_3way(mid1 + 1, mid2);
    int m3 = find_3way(mid2 + 1, high);

    return m1+m2+m3;

}

int main()
{
	int n;
	cout<<"Enter the size"<<endl;
	cin>>n;

	Child ob;
	ob.input(n);
	cout<<"2-way ->"<<ob.find_2way(0,n-1)<<endl;
	cout<<"3-way ->"<<ob.find_3way(0,n-1)<<endl;

}