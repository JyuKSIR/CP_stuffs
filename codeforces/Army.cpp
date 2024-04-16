#include<bits/stdc++.h>
using namespace std;

int main(){
int n,a,b,sum=0;
cin>>n;
int ar[n];
for(int i=0; i<n-1; ++i){
    cin>>ar[i];
}
cin>>a>>b;
for(int j=a-1; j<b-1; ++j){
    sum=sum+ar[j];
}
cout<<sum;

return 0;
}