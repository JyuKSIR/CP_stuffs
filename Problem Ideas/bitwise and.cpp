// given an array of n size, if you can make a subsequence of size m which
// bitwise and is k print yes else no
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
  int n, m, k; cin >> n >> m >> k;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x >= k) v.push_back(x);
  }
  if ((int)v.size() < m) {
    cout << "No\n";
    return;
  }
  sort(v.rbegin(), v.rend());
  int ans = v[0];
  for (int i = 1; i < m; i++) ans &= v[i];
  cerr << ans << '\n';
  if (ans >= k) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--) solve();
}
