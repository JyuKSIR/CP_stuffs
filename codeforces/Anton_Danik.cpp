#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, dcount=0, acount=0;
    cin>>n;
    string s, ans;
    cin>>s;
    while(n--){
        (s[n]=='D'? dcount++ : acount++);
    }
    ans=(dcount>acount? "Danik" :dcount==acount? "Friendship" : "Anton" );
    cout<<ans;
return 0;
}