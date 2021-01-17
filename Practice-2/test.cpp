#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int val=0;

void findNum(vector<int>v,int p)
{
	//cout<<V.size()<<endl;
	cout<<"vector"<<endl;
	for(int i=0;i<v.size();i++)
    {
    	for(int j=0;j<v.size();j++)
    	{
    		if(v[j]==p-v[i])
    		{
    			cout<<v[i]<<" "<<v[j]<<endl;
    			return;
    		}
    	}
    }
}

void findNummap(vector<int>v,int p)
{
	int n=v.size();
	cout<<"Map"<<endl;
	unordered_map<int,int>m;
	for(int i=0;i<n;i++)
	{
		m[v[i]]++;
	}
	for(int i=0;i<n;i++)
	{
		if(m[p-v[i]]>=1)
		{
			cout<<v[i]<<" "<<p-v[i]<<endl;
			return ;
			
		}
	}
}

void findSort(vector<int>v,int p)
{
	cout<<"Two pointer"<<endl;
	sort(v.begin(),v.end());
	int i=0,j=v.size()-1;
	while(i<j)
	{
		if(v[i]+v[j]==p)
		{
			cout<<v[i]<<" "<<v[j]<<endl;
			return;
		}
		else if(v[i]+v[j]<p)
		{
			i++;
		}
		else
		{
			j--;
		}
	}
}

int main()
{
	ofstream outData;
	outData.open("output.csv");
	int t;
	cin>>t;
	while(t--){
	int n,p,m1,m2,m3;
	cout<<"Enter the size of the array"<<endl;
	cin>>n;
	cout<<"Enter the elements of the array"<<endl;
	vector<int>v(n);
	for(int i=0;i<n;i++) cin>>v[i];

	

	cout<<"Enter the integer"<<endl;
    cin>>p;
    auto start = high_resolution_clock::now(); 
	findNum(v,p);
	 auto stop = high_resolution_clock::now(); 
	 auto duration = duration_cast<microseconds>(stop - start); 
  
    m1=duration.count();
    //findNum(v,p);
    start = high_resolution_clock::now(); 
    findNummap(v,p);
	 stop = high_resolution_clock::now(); 
	  duration = duration_cast<microseconds>(stop - start); 
  
    m2=duration.count(); 
    //findNummap(v,p);
    start = high_resolution_clock::now(); 
    findSort(v,p);
	stop = high_resolution_clock::now(); 
	duration = duration_cast<microseconds>(stop - start); 
  
    m3=duration.count();     
    //findSort(v,p);
    outData<<val++<<","<<m1<<","<<m2<<","<<m3<<endl;
}
}