#include<bits/stdc++.h>
using namespace std;

class Parent{
public:
	void bubbleSort(int *v,int s,int e);
	void selectionSort(int *v,int s,int e);
	void insertionSort(int *v,int s,int e);
	void print(int v[],int n);


};

class Child:public Parent{
public:
	void merge(int a[],int s,int mid,int e);
	void mergesort_bubble(int a[],int s,int e);
	void mergesort_selection(int a[],int s,int e);
	void mergesort_insertion(int a[],int s,int e);

};

void Parent::print(int v[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

void Parent::bubbleSort(int *v,int s,int e)
{
	int temp;
	for(int i=s;i<=e;i++)
	{
		for(int j=s;j<=e;j++)
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
}

void Parent::insertionSort(int *v,int s,int e)
{
	int j=0,temp;
	for(int i=s+1;i<=e;i++)
	{
		j=i;
		while(j!=s && v[j]<v[j-1])
		{
			temp=v[j];
			v[j]=v[j-1];
			v[j-1]=temp;
			j--;
		}
	}
}

void Parent::selectionSort(int *v,int s,int e)
{
	int p,i,j,min1,ind;
	for( i=s;i<=e;i++)
	{
		min1=v[i];p=0;
		for( j=i+1;j<=e;j++)
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

}

void Child::merge(int a[],int s,int mid,int e)
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

void Child::mergesort_bubble(int a[],int s,int e)
{
	int mid=s+(e-s)/2;
	if(e-s<5 and s<e)
	{
		bubbleSort(a,s,e);
		return ;
	}
	else if(s<e)
	{
		mergesort_bubble(a,s,mid);
		mergesort_bubble(a,mid+1,e);
	}

	merge(a,s,mid,e);
	
}

void Child::mergesort_selection(int a[],int s,int e)
{
	int mid=s+(e-s)/2;
	if(e-s<5 and s<e)
	{
		selectionSort(a,s,e);
		return ;
	}
	else if(s<e)
	{
		mergesort_selection(a,s,mid);
		mergesort_selection(a,mid+1,e);
	}

	merge(a,s,mid,e);
	
}

void Child::mergesort_insertion(int a[],int s,int e)
{
	int mid=s+(e-s)/2;
	if(e-s<5 and s<e)
	{
		insertionSort(a,s,e);
		return ;
	}
	else if(s<e)
	{
		mergesort_insertion(a,s,mid);
		mergesort_insertion(a,mid+1,e);
	}

	merge(a,s,mid,e);
	
}



int main()
{
	int n;
	cout<<"Enter the no.of elements"<<endl;
	cin>>n;

	int a[n];
	cout<<"Enter the elements"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}


	Child ob;

	cout<<"--------merge+bubble--------"<<endl;
	ob.mergesort_bubble(a,0,n-1);
	ob.print(a,n);


	cout<<"--------merge+selection--------"<<endl;
	ob.mergesort_selection(a,0,n-1);
	ob.print(a,n);


	cout<<"--------merge+insertion--------"<<endl;
	ob.mergesort_insertion(a,0,n-1);
	ob.print(a,n);
}