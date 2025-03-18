#include <bits/stdc++.h>
using namespace std;

const int lg = 4;

int main() {
    int n, m; cin >> n >> m;

    vector<int> t[n + 1]; // 1 indexed
    int d[n + 1] = {}, anc[n + 1][lg]{};

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        t[u].push_back(v);
    }

    function<void(int, int)> dfs = [&](int s, int p) {
        d[s] = d[p] + 1; // depth setting
        anc[s][0] = p; // First node parent (2^0 = 1)
        for(int j = 1; j < lg; j++) {
            if(anc[s][j - 1] == -1) {
                anc[s][j] = -1;
            } else {
                anc[s][j] = anc[anc[s][j - 1]][j - 1]; // Parent of parent
            }
        }

        for(auto c : t[s]) {
            dfs(c, s);
        }
    };

    function<int(int, int)> kth = [&](int u, int k) {
        for(int j = lg - 1; ~j; j--) {
            if((k >> j) & 1) u = anc[u][j];
            if(u == -1) break;
        }
        return u;
    };

    function<int(int, int)> lca = [&](int u, int v) {
        if(d[u] > d[v]) {
            swap(u, v);
        }
        int diff = d[v] - d[u];
        v = kth(v, diff);

        if(u == v) return u;

        for(int j = lg - 1; ~j; j--) {
            if(anc[u][j] != anc[v][j]) {
                u = anc[u][j];
                v = anc[v][j];
            }
        }
        return anc[u][0];
    };

    function<void(int)> show = [&](int n){
        for(int i=0; i<=n; i++){
            for(int j=0; j<lg; j++){
                cout << anc[i][j] << "  ";
            }
            cout << "\n";
        }
        cout << "\n";
    };

    dfs(1, -1);
    cout << lca(5, 6) << endl;
    cout << kth(4,1) << "\n";
    show(n);
}
// input 
// 6 5
// 1 2
// 1 3
// 2 4
// 2 5
// 3 6
