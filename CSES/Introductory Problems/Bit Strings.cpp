// https://cses.fi/problemset/task/1617/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll m = 1e9 + 7;

ll binex(ll a, ll b, ll m) {
  a %= m;
  ll ans = 1;
  while (b) {
    if (b & 1) {
      ans = ans * a % m;
    }
    a = a * a % m;
    b >>= 1;
  }
  return ans;
}

int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  ll n; cin >> n;
  cout << binex(2, n, m);
}
