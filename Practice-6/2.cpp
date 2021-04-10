#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>p1,pair<int,int>p2)
{
    return (double)p1.first/p1.second>(double)p2.first/p2.second;
}

int main()
{
    long long n,maxwt,i=0;
    cin>>n>>maxwt;
    vector<pair<int,int> >v;
    for(i=0;i<n;i++)
    {
        int s,e;
        cin>>s>>e;
        v.push_back(make_pair(s,e));
    }
    sort(v.begin(),v.end(),comp);
    double ans=0;
    i=0;
    while(maxwt-v[i].second>=0&&i<n)
    {
        ans+=v[i].first;
        maxwt-=v[i].second;
        i++;
    }
    //cout<<ans<<endl;
    if(maxwt==0||i==n)
    {
        cout<<ans;
    }
    else
    {
        ans+=(double)(((double)v[i].first/v[i].second)*(maxwt));
        cout<<ans;
    }
    return 0;
}

