// How many triplets are there where for every i < j < k the conditons a[i] < a[j] > a[k] holds
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;

template <typename num_t>
using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
  ll n; cin >> n;
  ll a[n];
  ordered_set<array<ll, 2>> l, r;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    r.insert({a[i], i});
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    r.erase({a[i], i});
    ll sleft = l.order_of_key({a[i], -1});
    ll sright = r.order_of_key({a[i], -1});
    ans += (sleft * sright);
    l.insert({a[i], -1});
  }
  cout << ans << '\n';
}

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
}
