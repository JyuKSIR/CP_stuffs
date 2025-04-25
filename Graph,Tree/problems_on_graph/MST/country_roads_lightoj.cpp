#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double


struct DSU{

    vector<int> par,sz;

    DSU(int n) : par(n,0),sz(n,1){
        for(int i=0; i<n; i++) par[i] = i;
    }

    int find(int i){
        if(i == par[i]) return i;
        return par[i] = find(par[i]);
    }

    bool same(int i,int j){
        return find(i) == find(j);
    }

    void join(int i,int j){
        i = find(i);
        j = find(j);
        if(i != j){
            if(sz[i] < sz[j]) swap(i,j);
            par[j] = i;
            sz[i] += sz[j];
        }
    }
};

void solve(){

    int n,m; cin >> n >> m;

    vector<array<int,3>> g;
    vector<pair<int,int>> dg[n];

    for(int i=0; i<m; i++){
        int u,v,w; cin >> u >> v >> w;
        g.push_back({w,u,v});
    }

    int t; cin >> t;

    sort(g.begin(),g.end());

    DSU d(n);

    for(auto e : g){
        int u = e[1], v = e[2], w = e[0];
        if(d.same(u,v)) continue;
        d.join(u,v);
        dg[u].push_back({v,w});
        dg[v].push_back({u,w});
    }

    int dis[n],vis[n]{};
    memset(dis, -1, sizeof(dis));
    dis[t] = 0;

    function<void(int)> dfs = [&](int s){
        vis[s] = 1;
        for(auto p : dg[s]){
            auto [c,w] = p;
            if(!vis[c]){
                dis[c] = max(dis[s],w);
                dfs(c);
            }
        }
    };

    dfs(t);

    for(int i=0; i<n; i++){
        if(dis[i] == -1){
            cout << "Impossible\n";
        }
        else cout << dis[i] << "\n";
    } 
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t,i=1; cin >> t;

    while(t--){
        cout << "Case " << i << ":\n";
        solve();
        i++;
    }

  return 0;
}
