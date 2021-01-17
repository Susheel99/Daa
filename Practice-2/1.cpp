#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

class pairsum{
public:
	vector<int>V;
	int P;
	int val=0;
	pairsum(vector<int>v,int p){
		for(int i=0;i<v.size();i++)
			V.push_back(v[i]);
		P=p;
	}
	void findNum();
	void findNummap();
	void findSort();
};



void pairsum::findNum()
{
	//cout<<V.size()<<endl;
	cout<<"vector"<<endl;
	for(int i=0;i<V.size();i++)
    {
    	for(int j=0;j<V.size();j++)
    	{
    		if(V[j]==P-V[i])
    		{
    			cout<<V[i]<<" "<<V[j]<<endl;
    			return;
    		}
    	}
    }
}

void pairsum::findNummap()
{
	int n=V.size();
	cout<<"Map"<<endl;
	unordered_map<int,int>m;
	for(int i=0;i<n;i++)
	{
		m[V[i]]++;
	}
	for(int i=0;i<n;i++)
	{
		if(m[P-V[i]]>=1)
		{
			cout<<V[i]<<" "<<P-V[i]<<endl;
			return ;
			
		}
	}
}

void pairsum::findSort()
{
	cout<<"Two pointer"<<endl;
	sort(V.begin(),V.end());
	int i=0,j=V.size()-1;
	while(i<j)
	{
		if(V[i]+V[j]==P)
		{
			cout<<V[i]<<" "<<V[j]<<endl;
			return;
		}
		else if(V[i]+V[j]<P)
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
	ofstream outfile;
	outfile.open("output.csv");
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

    //creating a pairsum object
    pairsum ob(v,p);


    auto start = high_resolution_clock::now(); 
	ob.findNum();
	 auto stop = high_resolution_clock::now(); 
	 auto duration = duration_cast<microseconds>(stop - start); 
  
    m1=duration.count();
    //findNum(v,p);
    start = high_resolution_clock::now(); 
    ob.findNummap();
	 stop = high_resolution_clock::now(); 
	  duration = duration_cast<microseconds>(stop - start); 
  
    m2=duration.count(); 
    //findNummap(v,p);
    start = high_resolution_clock::now(); 
    ob.findSort();
	stop = high_resolution_clock::now(); 
	duration = duration_cast<microseconds>(stop - start); 
  
    m3=duration.count();     
    //findSort(v,p);
    outfile<<val++<<","<<m1<<","<<m2<<","<<m3<<endl;
}
}