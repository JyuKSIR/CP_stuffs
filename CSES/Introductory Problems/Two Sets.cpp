// https://cses.fi/problemset/task/1092
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  ll n; cin >> n;
  ll x = (n * (n + 1)) / 2;
  if (x & 1) {
    cout << "NO";
    return 0;
  }
  ll s = x / 2;
  int vis[n + 1]{};
  vector<ll> v1, v2;
  for (ll i = n; i > 0; i--) {
    if (s >= i) {
      v1.push_back(i);
      s -= i;
      vis[i] = 1;
      if (s == 0) break;
    } 
  }
  for (ll i = 1; i <= n; i++) {
    if (!vis[i]) v2.push_back(i);
  }
  reverse(v1.begin(), v1.end());
  cout << "YES\n" << v1.size() << '\n';
  for (auto &i : v1) cout << i << ' ';
  cout << '\n' << v2.size() << '\n';
  for (auto &i : v2) cout << i << ' ';
}
