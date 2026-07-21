// https://cses.fi/problemset/task/1074/
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
  sort(a, a + n);
  ll m = a[n / 2], ans = 0;
  for (int i = 0; i < n; i++) {
    ans += abs(m - a[i]);
  }
  cout << ans << '\n';
}
