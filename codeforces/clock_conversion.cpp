#include<bits/stdc++.h>
using namespace std;

void solve(){
    string time;
    int hour, min;
    char colon;
    cin>>hour>>colon>>min;
    time=(hour<12? "AM":"PM");
    if(hour==0){
        hour+=12;
    }
    else if(hour>12){
        hour-=12;
    }
cout<<(hour<10? "0": "")<<hour<<colon<<(min<10? "0": "")<<min<<" "<<time<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--){
     solve();
    }
}