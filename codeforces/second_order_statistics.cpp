#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<int>v;
    for(int i=0; i<n; ++i){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=0; i<n; ++i){
        if(v[i]>v[0]){
            cout<<v[i];
            break;
        }
        else if(i==n-1){
            cout<<"NO";
        }
    }

return 0;
}