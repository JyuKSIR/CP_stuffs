// https://cses.fi/problemset/task/2183/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  ll n; cin >> n;
  ll a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  ll s = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > s + 1) break;
    s += a[i];
  }
  cout << s + 1 << '\n';
}
