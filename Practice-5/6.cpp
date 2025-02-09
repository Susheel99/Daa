#include<bits/stdc++.h>
using namespace std;

class Parent{
public:
	int n=9;
	vector<int> arr = {45, 35, 15, 30, 10, 12, 6, 5, 20};

	void Print(vector<int>& vec, int n);
};

void Parent::Print(vector<int>& vec, int n){
    cout << "Max Heap: [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

class Child:public Parent{
public:
	void insert(vector<int> &v,int n);
	void findMin(vector<int>h,int key);

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

void Child::findMin(vector<int>h, int n)
{
	set<int>s;
    int minimumElement = h[n / 2];
    s.insert(minimumElement);
 
    for (int i = 1 + n / 2; i < n; ++i){
    	s.insert(h[i]);
    }
        

    auto it=s.begin();
    cout<<"min elements"<<endl;
    cout<<*it<<" "<<*(++it)<<endl;
    
}

int main()
{
	Child ob;
	int n;
	//ob.insert(ob.arr,2);
	ob.Print(ob.arr,ob.arr.size());
	ob.findMin(ob.arr,ob.arr.size());
	

}