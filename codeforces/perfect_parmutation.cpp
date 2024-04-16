#include<bits/stdc++.h>
using namespace std;

int main(){
int n,a=0;
cin>>n;
if(n%2==1){
    cout<<"-1";
    return 0;
}
else{
    for(int i=1; i<=n; i++){
        if(i%2==1){
           a=i+1;
           cout<<a;   
        }
        else{
            a=i-1;
            cout<<a;
        }
        cout<<" ";
    }
}

return 0;
}