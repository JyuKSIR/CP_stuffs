// https://cses.fi/problemset/task/1618/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  ll n; cin >> n;
  ll ans = 0;
  while (n > 0) {
    ans += n / 5;
    n /= 5;
  }
  cout << ans << '\n';
}
