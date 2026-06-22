// https://cses.fi/problemset/task/1619/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n; cin >> n;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    mp[a]++;
    mp[b]--;
  }
  int ans = 0, s = 0; 
  for (auto [a, b] : mp) {
    // << a << ' ' << b << '\n';
    s += b;
    ans = max(ans, s);
  }
  cout << ans;
}
