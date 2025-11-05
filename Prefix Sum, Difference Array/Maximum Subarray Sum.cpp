// https://cses.fi/problemset/task/1643/
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n; cin >> n;
  ll a[n + 1]{}, ps[n + 1]{};
  for(ll i = 1; i <= n; i++){
    cin >> a[i];
  }
  for(ll i = 1; i <= n; i++){
    ps[i] = ps[i - 1] + a[i];
  }
  ll mn = 0;
  ll ans = a[1];
  for(ll i = 1; i <= n; i++){
    ans = max(ans, ps[i] - mn);
    mn = min(mn, ps[i]);
  }
  cout << ans << "\n";

  return 0;
}
// p[r] - p[l-1] this segment will be mas if p[l-1] is minimized
