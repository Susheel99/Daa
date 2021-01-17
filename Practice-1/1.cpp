#include<bits/stdc++.h>
using namespace std;



int main()
{
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;

    vector<int>v;
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
    for(auto c:v)
    {
        cout<<c<<endl;
    }

return 0;
}