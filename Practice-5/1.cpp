#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>v)
{
	int temp,n=v.size();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(v[j]>v[j+1])
			{
				temp=v[j];
				v[j]=v[j+1];
				v[j+1]=temp;
			}
		}
	}
	cout<<endl;
	cout<<"Bubble Sort-> ";
	for(int i=0;i<n;i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;

}

int main()
{
	int n;
	cout<<"Enter the no.of elements"<<endl;
	cin>>n;
	vector<int>v(n);
	cout<<"Enter the elements"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	bubbleSort(v);
}