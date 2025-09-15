#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define i28 __int128
using namespace std;

bool f(ll x, ll k){
  i28 bl = (i28)x * (x + 1) * (2 * x + 1);
  if(bl <= 6ll * k) return 0;
  else return 1;
}

void solve() {
  ll n;
  cin >> n;

  ll l = 0, r = 1e9;
  while(l <= r){
    ll m = (r + l) / 2;
    if(f(m, n)) r = m - 1;
    else l = m + 1;
  }

  ll bs = r;
  ll ck = (bs * (bs + 1) * (2 * bs + 1)) / 6;

  if(ck == n){
    cout << (bs * (bs + 1)) / 2 << "\n";
  }
  else{
    ll mr = n - ck;
    ll add = (mr + bs) / (bs + 1);
    cout << (bs * (bs + 1)) / 2 + add << "\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
// https://codeforces.com/gym/105863/problem/B
