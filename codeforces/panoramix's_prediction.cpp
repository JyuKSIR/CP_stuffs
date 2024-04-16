#include<bits/stdc++.h>
using namespace std;

int main(){

int n,m,a=0,count=0;
cin>>n>>m;
for(int i=n+1; i<=m; i++){
    count=0;
    for(int j=2; j<i; j++){
        if(i%j==0){
            count++;
            break;
        }
    }
    if(count==0){
            a=i;
            break;
        }
}
if(a==m){
    cout<<"YES";
}
else{
    cout<<"NO";
}
return 0;
}