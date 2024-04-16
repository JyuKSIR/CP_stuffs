#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.size(), step=0;
    for(int i=0; i<n; ++i){
        if(s[i]==s[i+1]){
           step++;
        if(step==6){
        cout<<"YES";
        break;
        } 
    } else step = 0;
    }
    if(step == 0) cout << "NO";

    return 0;
}