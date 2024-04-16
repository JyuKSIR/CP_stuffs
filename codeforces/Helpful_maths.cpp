#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.size();
    int imin;
    char temp;
    for(int i=0; i<n-2; i+=2)
    {
        imin=i;
        for(int j=i+2; j<n; j+=2)
        {
            if(s[imin]>s[j])
            {
                imin=j;
            }
        }
        temp=s[imin];
        s[imin]=s[i];
        s[i]=temp;
    }
    cout<<s;
    return 0;
}
