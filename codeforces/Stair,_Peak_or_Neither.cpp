#include<bits/stdc++.h>
using namespace std;

int main(){

    int t,a,b,c;
    cin>>t;
    for(int i=1; i<=t; ++i){
        cin>>a>>b>>c;

        if(a<b && b<c){
            cout<<"STAIR"<<endl;
        }
        else if(a<b && b>c){
            cout<<"PEAK"<<endl;
        }
        else{
            cout<<"NONE"<<endl;
        }
    }   
    return 0;
}