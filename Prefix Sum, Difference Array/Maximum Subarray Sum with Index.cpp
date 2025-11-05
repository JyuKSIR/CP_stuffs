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
  ll mn = 0, in = 0, l = 1, r = 1;
  ll ans = a[1];
  for(ll i = 1; i <= n; i++){
    ll cur = ps[i] - mn;
    if(cur > ans){
      ans = cur;
      r = i;
      l = in + 1;
    }
    if(ps[i] < mn){
      in = i;
      mn = ps[i];
    }
    // ans = max(ans, ps[i] - mn);
    // mn = min(mn, ps[i]);
  }
  cout << ans << "\n";
  cout << l << " " << r << "\n"; 

  return 0;
}
