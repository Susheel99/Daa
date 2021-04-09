#include<bits/stdc++.h>
using namespace std;

void insert(vector<int>v,int n)
{
	int i,temp;
	i=n;temp=v[i];
	while(i>1 && temp>v[i/2])
	{
		v[i]=v[i/2];
		i=i/2;
	}
	v[i]=temp;

	for(int i=1;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

int findMinimumElement(vector<int>heap, int n)
{
	set<int>s;
    int minimumElement = heap[n / 2];
    s.insert(minimumElement);
 
    for (int i = 1 + n / 2; i < n; ++i){
        cout<<"Heap-> "<<heap[i]<<endl;
    	s.insert(heap[i]);
        //minimumElement = min(minimumElement, heap[i]);
    }

    auto it=s.begin();
    cout<<"min elements"<<endl;
    cout<<*it<<" "<<*(++it)<<endl;
    return minimumElement;
}

int main()
{
	cout<<"Enter the number of elements"<<endl;
	int n;
	cin>>n;

	vector<int>a(n);
	cout<<"Enter the elements"<<endl;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}

	vector<int>v;
	v.push_back(-1);
	for(int i=1;i<=n;i++)
	{
		v.push_back(a[i]);
	    insert(v,v.size()-1);
	}

	//cout<<"The minimum element in the heap is-> ";
	findMinimumElement(v,v.size());
	

}
