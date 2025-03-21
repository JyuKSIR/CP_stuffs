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

void solve() {
    int x; 
    cin >> x;

    function<bool(int, int)> f = [](int a, int b) {
        int c = a ^ b;
        if (a + b > c && a + c > b && b + c > a) {
            return 0;
        }
        return 1;
    };

    int l = 0, r = x-1;

    while (l <= r) {
        int m = (l + r) / 2;
        if (f(m, x)) {
            l = m + 1; 
        } else { 
            r = m - 1; 
        }
    }
    if(l == x){
        cout << -1 << "\n";
        return;
    }
    cout << l << "\n";
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
