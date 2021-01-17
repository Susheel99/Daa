#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define ll long long

class GCD{
public:
	int a,b,lcm;

	GCD(int x,int y){
		a=x;
		b=y;
	}

	void gcd();

	int gcd_euclid(int a,int b);       

	void gcd_primefactorization();         //By using primefactorization method used in 3rd question.

};

void GCD::gcd()
{
	cout<<"---- Brute Force approach ----"<<endl;
	int ans=-1;
		for(int i=1;i<=min(a,b);i++)
		{
			if(a%i==0 and b%i==0)
				ans=i;
		}
	lcm=(a*b)/ans;
	cout<<"GCD of "<<a<<" and "<<b<<" is "<<ans<<endl;
	cout<<"LCM -"<<lcm<<endl;
}

int GCD::gcd_euclid(int a,int b)            //Euclid's algorithm
{
	if(b==0)
		return a;
	return gcd_euclid(b,a%b);
}

ll power(int n,int p)                       //fast exponentiation (to compute power of a number)
{
	if(p==0)
		return 1;

	ll subprob=power(n,p/2);

	if(p&1)
		return n*subprob*subprob;

	return subprob*subprob;
}

map<int,int> prime_factorization(int n)     //function returns map containing primefactors with there frequency
{
	map<int,int>m;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			while(n%i==0)
			{
				n=n/i;
				m[i]++;
			}
		}
	}
	if(n!=1)
	{
		m[n]++;
	}
	return m;
}

void GCD::gcd_primefactorization()
{
	cout<<"---- Using Prime Factorization ----"<<endl;
	map<int,int>m1,m2,m3;

	m1=prime_factorization(a);
	m2=prime_factorization(b);
			
	for(auto it=m1.begin();it!=m1.end();it++)
	{
		m3[it->first]=min(it->second,m2[it->first]);
	}


	ll res=1;
	for(auto it=m3.begin();it!=m3.end();it++)
	{
		res=res*power(it->first,it->second);
	}
	lcm=(a*b)/res;
	cout<<"GCD -"<<res<<endl;
	cout<<"LCM -"<<lcm<<endl;
}

int main()
{
	int a,b;
	cout<<"Enter two numbers to compute GCD:"<<endl;
	cin>>a>>b;
	GCD g(a,b);

	auto start = high_resolution_clock::now(); 
	g.gcd();
	 auto stop = high_resolution_clock::now(); 
	 auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
	

	
	cout<<"---- Euclid's algorithm ----"<<endl;
	 start = high_resolution_clock::now(); 
	 ll gcd=g.gcd_euclid(a,b);
	cout<<"GCD -"<<gcd<<endl;
	cout<<"LCM -"<<(a*b)/gcd<<endl;
	 stop = high_resolution_clock::now(); 
	  duration = duration_cast<microseconds>(stop - start); 
  
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 


	 start = high_resolution_clock::now();
	 g.gcd_primefactorization();
	 stop = high_resolution_clock::now();
	 duration = duration_cast<microseconds>(stop - start); 
  
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;  

	return 0;
}