#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> g[2 * n], gr[2 * n], f;
    vector<array<int, 4>> cm;
    int vis[2 * n] = {}, who[2 * n];
    int ans[n];
    set<int> sol;

    for (int i = 0; i < m; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        a--; b--;
        a *= 2; b *= 2;

        if (t == 1) {
            // x ∨ y → ¬x → y, ¬y → x
            g[a ^ 1].push_back(b);
            g[b ^ 1].push_back(a);
            gr[b].push_back(a ^ 1);
            gr[a].push_back(b ^ 1);
        } else if (t == 2) {
            // ¬x → ¬y = x → ¬y
            g[a].push_back(b ^ 1);
            gr[b ^ 1].push_back(a);
        } else if (t == 3) {
            // ¬x ∨ ¬y = x → ¬y, y → ¬x
            g[a].push_back(b ^ 1);
            g[b].push_back(a ^ 1);
            gr[b ^ 1].push_back(a);
            gr[a ^ 1].push_back(b);
        } else if (t == 4) {
            // (x ∨ y) ∧ (¬x ∨ ¬y)
            g[a ^ 1].push_back(b);
            g[b ^ 1].push_back(a);
            gr[b].push_back(a ^ 1);
            gr[a].push_back(b ^ 1);

            g[a].push_back(b ^ 1);
            g[b].push_back(a ^ 1);
            gr[b ^ 1].push_back(a);
            gr[a ^ 1].push_back(b);
        }
    }

    for (int i = 0; i < k; i++) {
        int t, x, y, z;
        cin >> t >> x >> y >> z;
        x--; y--; z--;
        x *= 2; y *= 2; z *= 2;

        if (t == 1) {
            // x ∨ y ∨ z
            g[x ^ 1].push_back(y);
            g[x ^ 1].push_back(z);
            g[y ^ 1].push_back(x);
            g[y ^ 1].push_back(z);
            g[z ^ 1].push_back(x);
            g[z ^ 1].push_back(y);
            gr[y].push_back(x ^ 1);
            gr[z].push_back(x ^ 1);
            gr[x].push_back(y ^ 1);
            gr[z].push_back(y ^ 1);
            gr[x].push_back(z ^ 1);
            gr[y].push_back(z ^ 1);
        } else if (t == 2) {
            // ¬x ∨ ¬y ∨ ¬z
            g[x].push_back(y ^ 1);
            g[x].push_back(z ^ 1);
            g[y].push_back(x ^ 1);
            g[y].push_back(z ^ 1);
            g[z].push_back(x ^ 1);
            g[z].push_back(y ^ 1);
            gr[y ^ 1].push_back(x);
            gr[z ^ 1].push_back(x);
            gr[x].push_back(y ^ 1);
            gr[z ^ 1].push_back(y);
            gr[x].push_back(z ^ 1);
            gr[y ^ 1].push_back(z);
        }
    }

    function<void(int)> dfs1 = [&](int p) {
        vis[p] = 1;
        for (auto c : g[p]) {
            if (!vis[c]) dfs1(c);
        }
        f.push_back(p);
    };

    for (int i = 0; i < 2 * n; i++) {
        if (!vis[i]) dfs1(i);
    }

    function<void(int, int)> dfs2 = [&](int p, int r) {
        vis[p] = 0;
        who[p] = r;
        for (auto c : gr[p]) {
            if (vis[c]) dfs2(c, r);
        }
    };

    int ct = 0;
    for (int i = 2 * n - 1; i >= 0; i--) {
        if (vis[f[i]]) {
            dfs2(f[i], ct);
            ct++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (who[2 * i] == who[2 * i + 1]) {
            cout << "Impossible.\n";
            return;
        }
        ans[i] = (who[2 * i] > who[2 * i + 1]) ? 1 : 0;
        sol.insert(i + 1);
    }

    for (auto [t, x, y, z] : cm) {
        if (t == 1) {
            if (!ans[x] && !ans[y] && !ans[z]) {
                cout << "Impossible.\n";
                return;
            }
        }
        if (t == 2) {
            if (ans[x] && ans[y] && ans[z]) {
                cout << "Impossible.\n";
                return;
            }
        }
    }

    cout << "Possible " << sol.size();
    for (auto x : sol) cout << " " << x;
    cout << ".\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, i = 1;
    cin >> t;

    while (t--) {
        cout << "Case " << i << ": ";
        solve();
        i++;
    }

    return 0;
}
