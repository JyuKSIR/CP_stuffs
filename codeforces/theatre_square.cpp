#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long m,n,a,p,q,ans; //long long has a wider range like billion in int

    cin>>m>>n>>a;

    p=m/a;
    q=n/a;

    if(m%a!=0)
        p++;
    if(n%a!=0)
        q++;

    ans=p*q;

    cout<<ans;

    return 0;
}
