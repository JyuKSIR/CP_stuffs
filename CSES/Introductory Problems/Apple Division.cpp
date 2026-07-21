// https://cses.fi/problemset/task/1623/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  ll n; cin >> n;
  ll a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll sz = (1 << n), ans = 1e9;
  for (int i = 0; i < sz; i++) {
    ll s1 = 0, s2 = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        s1 += a[j];
      } else {
        s2 += a[j];
      }
    }
    ans = min(ans, abs(s1 - s2));
  }
  cout << ans;
}
