#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

void solve(){

    ll a, r, n, sum = 1, x = 1; cin >> a >> r >> n;
    const ll m = 1000003;

    for(int i = 1; i < n; i++){
        x = (x * r) % m;
        sum = (sum + x) % m;
    }
    cout << (a * sum) % m << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;

    while(t--){
       solve();
    }

  return 0;
}
