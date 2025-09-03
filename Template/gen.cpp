#include <bits/stdc++.h>
using namespace std;

#define ll long long

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll gen_random(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rng);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("wtc.txt", "w", stdout);

    int n = gen_random(5, 10);
    int m = gen_random(1, n * (n - 1) / 2 - 1);

    cout << n << " " << m << endl;

    set<pair<int, int>> st;

    while (st.size() < m) {
        int u = gen_random(1, n);
        int v = gen_random(1, n);

        if (u == v) continue;

        if (u > v) swap(u, v);

        st.insert({u, v});
    }

    for (auto [u, v] : st) {
        cout << u << " " << v << endl;
    }

    return 0;
}
