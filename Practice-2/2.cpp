#include<bits/stdc++.h>
using namespace std;

class findn{
public:
	void method1();
	void method2();
	void method3();
};

void findn::method1()
{
	cout<<"linear search"<<endl;
	int arr[5000];
	int i=0;
	int val;
	while(true)
	{
		cout<<"Press 1 to enter:"<<endl;
		cout<<"Press 0 to exit:"<<endl;

		cin>>val;
		if(val)
			cin>>arr[i++];
		else
			break;
	}
	for(int k=0;k<i;k++)
	{
		if(arr[k]==-1){
			cout<<k<<endl;
			break;
		}
	}
}

void findn::method2()
{
	cout<<"Divide and conquer"<<endl;
	int arr[5000];
	int i=0;
	int val;
	while(true)
	{
		cout<<"Press 1 to enter:"<<endl;
		cout<<"Press 0 to exit:"<<endl;

		cin>>val;
		if(val)
			cin>>arr[i++];
		else
			break;
	}
	int l=0,h=i-1;
	int mid=(l+h)/2;
	while(l<h)
	{
		mid=(l+h)/2;
		if(arr[mid]==-1)
		{
			cout<<"found"<<endl;
			break;
		}
		else
		{
			l=mid+1;
		}
	}
	for(int i=mid;i>=0;i--)
	{
		if(arr[i]!=-1)
		{
			cout<<i+1<<endl;
			break;
		}
	}
}

void findn::method3()
{
	cout<<"Do while"<<endl;
	int arr[5000];
	int i=0;
	int val,res=INT_MAX;
	do{
		cout<<"Enter the element:";
		cin>>arr[i++];
		if(arr[i-1]==-1)
			res=min(res,i-1);

		cout<<"Press 1 to enter:"<<endl;
		cout<<"Press 0 to exit:"<<endl;
		cin>>val;
	}
	while(val);

	cout<<res<<endl;
}

int main()
{
	findn p;
	p.method1();
	p.method2();
	p.method3();
}