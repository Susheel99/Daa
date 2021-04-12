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
    int knpwt = 0; 
    double result = 0.0; 
 

    for (int i = 0; i < n; i++) {

        if (knpwt + v[i].second <= maxwt)
         {
            knpwt += v[i].second;
            result += v[i].first;
        }
 

        else
         {
            int remain = maxwt - knpwt;
            result += v[i].first* ((double)remain/ (double)v[i].second);
            break;
        }
    }
 
    cout<<result<<endl;
}

