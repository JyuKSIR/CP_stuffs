// https://codeforces.com/contest/1370/problem/A

#include<bits/stdc++.h>
using namespace std;

#define dbg(a) cerr<<__LINE__<<" no. line: "<<#a<<" = "<<a<<endl


void solve(){

    int n; cin >> n;
    // int ar[n];
    // for(int i=0; i<n; i++){
    //     ar[i] = i+1;
    // }
    // int res = 1;
    // for(int i=0; i<n-1; i++){
    //     for(int j=i+1; j<n; j++){
    //         int check = __gcd(ar[i],ar[j]);
    //         if(check > res){
    //             res = check;
    //         }
    //     }
    // }
    // cout << res << "\n";

    cout << n/2 <<"\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
     solve();
    }

  return 0;
}
