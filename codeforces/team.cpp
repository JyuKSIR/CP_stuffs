#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,num=0,term=0;
    cin>>n;
    int arr[n][3];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
       num=0;
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]==1){
                num++;
            }
        }
        if(num==2 || num==3){
            term++;
        }
    }
     cout<<term;

    return 0;
}

