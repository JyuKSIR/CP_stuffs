#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
double sum=0; 
double ans=0;
cin>>n;
double ar[n];
for(int i=0; i<n; i++){
    cin>>ar[i];
    sum=sum+ar[i];
}
ans=sum/n;
cout<<fixed<<setprecision(12)<<ans;
return 0;
}