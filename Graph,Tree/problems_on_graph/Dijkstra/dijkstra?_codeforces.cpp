//https://codeforces.com/contest/20/problem/C
#include <bits/stdc++.h>
using namespace std;

#define dbg(a) cerr << __LINE__ << " no. line: " << #a << " = " << a << endl

const long long INF = 1e13 + 10;

vector<vector<pair<long long, long long>>> g;
vector<long long> dist;
vector<long long> parent;
vector<int> vis;

void dijkstra(long long s, long long n) {
    dist.resize(n + 1, INF);
    vis.resize(n + 1, 0);
    parent.resize(n + 1, -1);

    set<pair<long long, long long>> st;
    st.insert({0, s});
    dist[s] = 0;

    while (!st.empty()) {
        auto n = *st.begin();
        long long wgt = n.first;
        long long par = n.second;
        st.erase(st.begin());
        if (vis[par]) continue;
        vis[par] = 1;
        for (auto chi : g[par]) {
            long long chi_n = chi.first;
            long long chi_wgt = chi.second;
            if (dist[par] + chi_wgt < dist[chi_n]) {
                dist[chi_n] = dist[par] + chi_wgt;
                st.insert({dist[chi_n], chi_n});
                parent[chi_n] = par;
            }
        }
    }
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("1_input.txt", "r", stdin);
    freopen("1_output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, m;
    cin >> n >> m;
    g.resize(n + 1);
    while (m--) {
        long long x, y, wt;
        cin >> x >> y >> wt;
        g[x].push_back({y, wt});
        g[y].push_back({x, wt});
    }
    dijkstra(1, n);
    if (dist[n] == INF) {
        cout << "-1";
    } else {
        vector<long long> ans;
        for (long long j = n; j != -1; j = parent[j]) {
            ans.push_back(j);
        }
        reverse(ans.begin(), ans.end());
        for (auto k : ans) {
            cout << k << " ";
        }
    }

    return 0;
}
