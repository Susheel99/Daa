#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

class Prime{
public:
	int N;
	vector<int>v;
	Prime(int value){
		N=value;
	}

	void navie_approach();

	void optimised_approach();

	//~Prime();
};

void Prime::navie_approach()
{
	cout<<"-----Navie Approach-----"<<endl;
	int n=N;
	    for(int i=2;i<=n;i++)
	    {
		   if(n%i==0)
		    {
			   while(n%i==0)
			   {
				 n=n/i;
			   }
		       v.push_back(i);
		    }
	    }
	    cout<<"The prime factors of "<<N<<" :"<<endl;
	    for(int i=0;i<v.size();i++)
	    {
		    cout<<v[i]<<" ";
	    }
	    cout<<endl;
	    v.clear();
}

void Prime::optimised_approach()
{
	cout<<"----optimised approach----"<<endl;
	int n=N;
		for(int i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				while(n%i==0)
				{
					n=n/i;
		        }
		        v.push_back(i);
			}
		}
		if(n!=1)
			v.push_back(n);

		cout<<"The prime factors of "<<N<<" :"<<endl;
		for(int i=0;i<v.size();i++)
			cout<<v[i]<<" ";

		cout<<endl;
		v.clear();
}

int main()
{
	cout<<"Enter the number for which you want to find prime factors:"<<endl;
	int n;
	cin>>n;
	Prime p(n);
	 
	p.navie_approach();
	
	cout<<endl;

	
	p.optimised_approach();
	 
	return 0;
}