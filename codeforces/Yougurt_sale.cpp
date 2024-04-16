#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n,a,b,money;
        cin>>n>>a>>b;
        if(a*2>b){
            if(n%2==0){
                money=b*(n/2);
            }
            else{
                money=b*(n/2)+a;
            }
        }
        else{
            money=n*a;
        }
        cout<<money<<"\n";
    }

return 0;
}