#include<bits/stdc++.h>
using namespace std;

int main(){
int k,l,m,n,d,step=0,ans=0;
cin>>k>>l>>m>>n>>d;
for(int i=1; i<=d; ++i){
    if(i%k!=0 && i%l!= 0 && i%m!=0 && i%n!=0){
        step++;
    }
}
ans=d-step;
cout<<ans;
return 0;
}