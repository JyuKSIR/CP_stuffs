// https://cses.fi/problemset/task/1646
// ref --> https://www.youtube.com/watch?v=PhgtNY_-CiY
#include<bits/stdc++.h>
using namespace std;

#define dbg(a) cerr<<__LINE__<<" no. line: "<<#a<<" = "<<a<<endl

void solve(){

    int n,q;
    cin >> n >> q;
    vector<int> store(n);
    for(int i=0; i<n; i++){
        cin >> store[i];
    }

    vector<long long> pref_sum(n+1);
    for(int i = 1; i<=n; i++){
        pref_sum[i] = pref_sum[i-1] + store[i-1];
    }  
    //pref[0] = 0
    //pref[1] = x[0]
    //pref[2] = x[1] + pref[1]
    //.....
    while(q--){
        int a,b;
        cin >> a >> b;
        cout << pref_sum[b] - pref_sum[a-1] << "\n";
    } 
}

int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();


  return 0;
}
