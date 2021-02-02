#include<bits/stdc++.h>
using namespace std;

#define ll long long

class subset{
public:
	vector<int>v;
	int k;
	subset(vector<int>V,int K){
		k=K;
		for(auto c:V)
			v.push_back(c);
	}
	void subsetsum();
};

void subset::subsetsum()
{
	ll sz=1<<(v.size()-1);

	for(int i=1;i<=sz;i++)
	{
		ll sum=0;
		for(int j=0;j<32;j++)
		{
			if(i&(1<<j))
			{
				sum=sum+v[j];
			}
		}
		if(sum==k){
			cout<<"Yes"<<endl;
			return ;
		}
	}
	cout<<"No"<<endl;
}


int main()
{
	int n;
	cout<<"Enter the size"<<endl;
	cin>>n;
	vector<int>v(n);


    cout<<"Enter the elements"<<endl;
	for(int i=0;i<n;i++)
		cin>>v[i];

	int k;
	cout<<"Enter the desired sum"<<endl;
	cin>>k;

	subset ob(v,k);

	ob.subsetsum();

}