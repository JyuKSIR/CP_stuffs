-- > (a + b) % x can be written by a % x = (x - b % x) % x
here we can minus b from x because we want a positive ans. and we always do overall mod % x because b itself can be equal to x;
what will happen then? take the values and do math
--> (a - b) % x can be written as a % y = b % y
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
    ll u = (-a[i] % x + x) % x; // (x - b % x) % x
    ll v = a[i] % y; // b % y
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
