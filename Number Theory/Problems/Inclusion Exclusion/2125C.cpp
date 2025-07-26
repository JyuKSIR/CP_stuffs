#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifdef LOCAL
#include "debugging_jinish.h"
#else
#define dbg(...) 1
#endif
 
template <typename num_t>
using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define ld long double

void solve(){
    ll l,r; cin >> l >> r;
	function<ll(ll)> shesh = [](ll n){
	    vector<ll> v = {2,3,5,7};
	    ll sz = v.size();
	    ll tot = 0;
	    for(ll i = 1; i < (1 << sz); i++){
	        ll pro = 1, setb = 0;
	        for(ll j = 0; j < sz; j++){
	            if(i & (1 << j)) {
	                pro *= v[j];
	                setb++;
	            }
	        }
	        if(setb & 1){
	            tot += (n/pro);
	        }
	        else tot -=(n/pro);
	    }
	    return n - tot;
	};
    ll last = shesh(r),
    first = shesh(l -1),
    ans = last - first;
    cout << ans << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;

    while(t--){
       solve();
    }

  return 0;
}
// here the logic of inclusion exclusion and subset using bt mask used
