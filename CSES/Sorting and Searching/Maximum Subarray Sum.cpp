// https://cses.fi/problemset/task/1643/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  ll n; cin >> n;
  ll a[n + 1]{}, ps[n + 1]{};
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (ll i = 1; i <= n; i++) {
    ps[i] = ps[i - 1] + a[i];
  }
  ll mn = 0;
  ll ans = a[1];
  for (ll i = 1; i <= n; i++) {
    ans = max(ans, ps[i] - mn);
    mn = min(mn, ps[i]);
  }
  cout << ans << "\n";
}
