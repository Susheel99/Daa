#include<bits/stdc++.h>
using namespace std;

int make_change(int *coins,int n,int money)
{
	int ans=0;
	while(money>0)
	{
		//address of the number just less than money
	    int idx=upper_bound(coins,coins+n,money)-1-coins;
	    cout<<coins[idx]<<" + ";
	    money=money-coins[idx];
	    ans++;
    }
return ans;
}

int main()
{
	int money;
	cin>>money;

	int coins[]={1,2,5,10,20,50,100,200,500,2000};
	int t=sizeof(coins)/sizeof(int);
    int ans=make_change(coins,t,money);
    cout<<endl;
	cout<<"No.of coins->"<<ans<<endl;

	return 0;
}