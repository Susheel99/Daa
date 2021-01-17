#include<bits/stdc++.h>
using namespace std;



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
	int n,p;
	cout<<"Enter the size of the array"<<endl;
	cin>>n;
	cout<<"Enter the elements of the array"<<endl;
	vector<int>v(n);
	for(int i=0;i<n;i++) cin>>v[i];

	

	cout<<"Enter the integer"<<endl;
    cin>>p;
    findNum(v,p);
    findNummap(v,p);
    findSort(v,p);
}