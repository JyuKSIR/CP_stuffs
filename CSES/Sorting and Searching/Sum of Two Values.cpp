// https://cses.fi/problemset/task/1640
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n, x; cin >> n >> x;
  int a[n];
  map<int,int> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  int f = -1, s = -1, z;
  for (int i = 0; i < n; i++) {
    z = x - a[i];
    mp[a[i]]--;
    if (mp.find(z) != mp.end() && mp[z] > 0) {
      f = i;
      break;
    } 
  }
  cerr << f << ' ' << z;
  for (int i = 0; i < n; i++) {
    if (a[i] == z && i != f) {
      s = i;
      break;
    }
  }
  if (f > -1 && s > -1) cout << f + 1 << ' ' << s + 1 << '\n';
  else cout << "IMPOSSIBLE";
}
