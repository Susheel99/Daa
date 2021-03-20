#include<bits/stdc++.h>
using namespace std;

class Parent{
public:
	int n;
	vector<int>arr;
	void input(int N)
	{
		n=N;
		cout<<"Enter the elements"<<endl;
		for(int i=0;i<n;i++)
		{
			int x;cin>>x;
			arr.push_back(x);
		}
	}
};

class Child:public Parent{
public:
	void insert(vector<int> v,int n);
	int findMinimumElement(vector<int>heap,int n);

};

void Child::insert(vector<int>v,int n)
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

int Child::findMinimumElement(vector<int>heap, int n)
{
	set<int>s;
    int minimumElement = heap[n / 2];
    s.insert(minimumElement);
 
    for (int i = 1 + n / 2; i < n; ++i){
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
	Child ob;
	int n;
	cout<<"Enter the size"<<endl;
	cin>>n;
	ob.input(n);

	

	vector<int>v;
	v.push_back(-1);
	for(int i=1;i<=n;i++)
	{
		v.push_back(ob.arr[i]);
	    ob.insert(v,v.size()-1);
	}

	//cout<<"The minimum element in the heap is-> ";
	ob.findMinimumElement(v,v.size());
	

}