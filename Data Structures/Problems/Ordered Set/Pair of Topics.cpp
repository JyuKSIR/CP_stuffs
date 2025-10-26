#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
template <typename num_t>
using ordered_set = tree<num_t, null_type, greater_equal<num_t>, rb_tree_tag, tree_order_statistics_node_update>; // greater equal is not optimzed

#define ll long long

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n; cin >> n;
  ll a[n], b[n], c[n], d[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];
  for(int i = 0; i < n; i++) {
   c[i] = a[i] - b[i];
   d[i] = b[i] - a[i];
  }
  ordered_set<ll> os;
  ll ans = 0;
  for(int i = 0; i < n; i++){
   ans += os.order_of_key(d[i]);
   os.insert(c[i]);
  }
  cout << ans << "\n";

  return 0;
}

// if we want to handle multiple case 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
template <typename num_t>
using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n; cin >> n;
  ll a[n], b[n], c[n], d[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];
  for(int i = 0; i < n; i++) {
   c[i] = a[i] - b[i];
   d[i] = b[i] - a[i];
  }
  ordered_set<array<ll,2>> os; // we will use pairs
  ll ans = 0;
  for(int i = 0; i < n; i++){
   ans += os.order_of_key({c[i],0});
   os.insert({d[i],i});
  }
  cout << ans << "\n";

  return 0;
}
