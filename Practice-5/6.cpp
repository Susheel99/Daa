#include<bits/stdc++.h>
using namespace std;

class Parent{
public:
	int n=9;
	vector<int> arr = {45, 35, 15, 30, 10, 12, 6, 5, 20};
	
	//arr.push_back(-1);
	// void input(int N)
	// {
	// 	n=N;
	// 	cout<<"Enter the elements"<<endl;
	// 	for(int i=0;i<n;i++)
	// 	{
	// 		int x;cin>>x;
	// 		arr.push_back(x);
	// 	}
	// }
};

class Child:public Parent{
public:
	void insert(vector<int> &v,int n);
	int findMinimumElement(vector<int>heap,int key);

};

void Child::insert(vector<int>&vec,int key)
{
	// Insert key at the end
    auto i = vec.size();
    vec.emplace_back(key);
 
    // Rearrange elements: Indices are not DRY :-(
    while (i > 0 && key > vec[i % 2 == 0 ? (i/2)-1 : i/2]){
        vec[i] = vec[i % 2 == 0 ? (i/2)-1 : i/2];
        i = i % 2 == 0 ? (i/2)-1 : i/2;
    }
    vec[i] = key;
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
	cout<<"Enter the element"<<endl;
	//cin>>n;
	//ob.input(n);

	//cout<<"The minimum element in the heap is-> ";
	ob.insert(ob.arr,2);
	ob.findMinimumElement(ob.arr,ob.arr.size());
	

}