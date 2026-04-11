// https://codeforces.com/contest/2125/problem/C
#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
  ll l, r;
  cin >> l >> r;

  function<ll(ll)> shesh = [](ll n) {
    vector<ll> v = {2, 3, 5, 7};
    ll sz = v.size();
    ll tot = 0;

    for (ll i = 1; i < (1 << sz); i++) {
      ll pro = 1, setb = 0;

      for (ll j = 0; j < sz; j++) {
        if (i & (1 << j)) {
          pro *= v[j];
          setb++;
        }
      }

      if (setb & 1) {
        tot += (n / pro);
      } else {
        tot -= (n / pro);
      }
    }

    return n - tot;
  };

  ll last = shesh(r);
  ll first = shesh(l - 1);
  ll ans = last - first;

  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
