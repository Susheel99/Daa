#include<bits/stdc++.h>
using namespace std;

void print(vector<int>v)
{
	for(auto c:v)
	{
		cout<<c<<" ";
	}
	cout<<endl;
}

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
	print(v);

}

void insertionSort(vector<int>v)
{
	int n=v.size(),j=0,temp;
	for(int i=1;i<n;i++)
	{
		j=i;
		while(j!=0 && v[j]<v[j-1])
		{
			temp=v[j];
			v[j]=v[j-1];
			v[j-1]=temp;
			j--;
		}
	}
	cout<<"Insertion Sort-> ";
	print(v);
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
	insertionSort(v);
}