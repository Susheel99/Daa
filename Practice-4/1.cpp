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
	int max_1way();
	int max_2way(int s,int e);
	int max_3way(int s,int e);
	int max_kway(int s,int e,int k);
};

int Child::max_1way()
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

int Child::max_2way(int s,int e)
{
	if(s==e)
		return arr[s];

	int mid=(s+e)/2;
	int a=max_2way(s,mid);
	int b=max_2way(mid+1,e);

	return max(a,b);
}

int Child::max_3way(int s, int e)
{

    if (s == e)
    {
        return arr[s];
    }

    if(s>e)
    {
        return INT_MIN;
    }

    int mid = (e - s + 1)/3;
    if(mid == 0){
        mid = 1;
    }
    int mid1 = s + mid - 1;
    int mid2 = mid1 + mid;

    int m1 = max_3way(s, mid1);
    int m2 = max_3way(mid1 + 1, mid2);
    int m3 = max_3way(mid2 + 1, e);

    return max(m1,max(m2,m3));
}

int Child::max_kway(int s, int e, int k)
{

    if (s == e)
    {
      return arr[s];
    }

    if(s>e)
    {
        return INT_MIN;
    }

    int mids[k];
    int mid = (e - s + 1)/k;
    if(mid == 0){
        mid = 1;
    }
    mids[0] = s + mid - 1;
    for(int i = 1; i<k; i++)
    {
        if(i>(e - s)){
            mids[i] = mids[0];
        }
        else{
            mids[i] = mids[i-1] + mid;
        }

    }
    int m1 = max_kway(s, mids[0], k);
    int m_i = m1;

    for(int i=0; i<k-1; i++)
    {
        int m2 = max_kway(mids[i] + 1, mids[i+1], k);
        if(m_i<m2){
            m_i = m2;
        }
    }


    int m3 = max_kway(mids[k-2] + 1, e, k);

    return max(m3,m_i);
}


int main()
{
	
	Child ob;
	int n;
	cout<<"Enter the size"<<endl;
	cin>>n;
	ob.input(n);
	cout<<"1-Way "<<ob.max_1way()<<endl;
	cout<<"2-Way "<<ob.max_2way(0,n-1)<<endl;
	cout<<"3-way "<<ob.max_3way(0,n-1)<<endl;
	cout<<"k-way "<<ob.max_kway(0,n-1,4)<<endl;
}