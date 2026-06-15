// https://cses.fi/problemset/task/1071
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
  ll a, b; cin >> a >> b;
  ll n = max(a, b);
  if (n & 1) {
    cout << (n * n) - n + 1 - (a - b) << '\n';
  } else {
    cout << (n * n) - n + 1 - (b - a) << '\n';
  }
}

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
}
