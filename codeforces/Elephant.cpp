#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,p;
    cin>>x;
    p=x/5;
    if(x%5!=0){
        p++;
    }
    cout<<p;
    return 0;
}