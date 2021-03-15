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

void selectionSort(vector<int>v)
{
	int p,i,j,min1,ind,n=v.size();
	for( i=0;i<n;i++)
	{
		min1=v[i];p=0;
		for( j=i+1;j<n;j++)
		{
			if(min1>v[j])
			{
				p++;
				ind=j;
				min1=v[j];
			}
		}
		if(p!=0){
		v[ind]=v[i];
		v[i]=min1;
	}
	}
	cout<<"selection Sort-> ";
	print(v);
}

void merge(int a[],int s,int mid,int e)
{
	int i=s,j=mid+1,k=s;
	int b[e+1];

	while(i<=mid && j<=e)
	{
		if(a[i]<a[j])
		{
			b[k++]=a[i++];
		}
		else
		{
			b[k++]=a[j++];
		}
	}
	while(i<=mid)
	{
		b[k++]=a[i++];
	}
	while(j<=e)
	{
		b[k++]=a[j++];
	}
	for(int i=s;i<=e;i++)
	{
		a[i]=b[i];
	}
}

void mergesort(int a[],int s,int e)
{
	if(s<e)
	{
		int mid=s+(e-s)/2;

		mergesort(a,s,mid);
		mergesort(a,mid+1,e);

		merge(a,s,mid,e);
	}
}

int main()
{
	int n;
	cout<<"Enter the no.of elements"<<endl;
	cin>>n;
	vector<int>v(n);
	int a[n];
	cout<<"Enter the elements"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	//bubbleSort(v);
	//insertionSort(v);
	//selectionSort(v);
	mergesort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}