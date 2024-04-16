#include<bits/stdc++.h>
using namespace std;

int main(){

int t,n,m,k,step=0;
cin>>t;
int ans[t];
for(int a=0; a<t; ++a){
    step=0;
    cin>>n>>m>>k;
    int left[n],right[m];
    for(int b=0; b<n; ++b){
        cin>>left[b];
    }
    for(int c=0; c<m; ++c){
        cin>>right[c];
    }
    for(int d=0; d<n; ++d){
        for(int e=0; e<m; ++e){
            if(left[d]+right[e]<=k){
                step++;
            }
        }
    }
  ans[a]=step;
}
for(int f=0; f<t; ++f){
    cout<<ans[f]<<"\n";
}
return 0;
}