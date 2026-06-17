// https://cses.fi/problemset/task/1754
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve(){
  int a, b; cin >> a >> b;
  if ((a + b) % 3 == 0 && 2 * a >= b && 2 * b >= a) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
 
int main(){
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
}
