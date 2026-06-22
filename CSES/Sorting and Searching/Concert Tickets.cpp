// https://cses.fi/problemset/task/1091/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m; cin >> n >> m;
  int a[n], b[m];
  multiset<int> ms;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ms.insert(a[i]);
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < m; i++) {
    auto it = ms.upper_bound(b[i]);
    if (it != ms.begin()) {
      it--;
      cout << *it << '\n';
      ms.erase(it);
    } else {
      cout << "-1\n";
    }
  }
}
