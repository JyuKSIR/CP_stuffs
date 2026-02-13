
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
  ll n, x, y; cin >> n >> x >> y;
  ll a[n];
  map<array<ll, 2>, ll> mp;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  ll ans = 0;
  for(int i = 0; i < n; i++){
    ll u = (-a[i] % x + x) % x;
    ll v = a[i] % y;
    ans += mp[{u,v}];
    mp[{a[i] % x, a[i] % y}]++;
  }
  cout << ans << "\n";
}

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
}
