#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,x,p=0;

    cin>>n>>k;

    vector<int> v;

    for(int i=0; i<n; i++)
    {
        cin>>x;
        v.push_back(x);
    }
    for(int i=0; i<n; i++)
    {
            if(v[i]>=v[k-1]&& v[i]>0){
                p++;
            }

    }
    cout<<p;
    return 0;
}
