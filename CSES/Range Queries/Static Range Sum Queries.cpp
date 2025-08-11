#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,q;
    cin >> n >> q;
    vector<int> store(n);
    for(int i = 0; i < n; i++) cin >> store[i];
    vector<long long> pref_sum(n+1);
    for(int i = 1; i <= n; i++){
        pref_sum[i] = pref_sum[i-1] + store[i-1];
    }  
    while(q--){
        int a,b;
        cin >> a >> b;
        cout << pref_sum[b] - pref_sum[a-1] << "\n";
    } 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

  return 0;
}
// https://cses.fi/problemset/task/1646
