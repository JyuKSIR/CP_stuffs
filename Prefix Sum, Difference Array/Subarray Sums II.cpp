// https://cses.fi/problemset/task/1661/
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, x; cin >> n >> x;
  map<ll,ll> mp;
  ll a[n + 1]{}, ps[n + 1]{};
  for(ll i = 1; i <= n; i++) cin >> a[i];
  for(ll i = 1; i <= n; i++){
    ps[i] = ps[i - 1] + a[i];
  }

  ll ans = 0;
  for (int i = 0; i <= n; i++) {
    if (mp.count(ps[i] - x)){
      ans += mp[ps[i] - x];
    }
    mp[ps[i]]++;
  }

  cout << ans;
  
  return 0;
}
