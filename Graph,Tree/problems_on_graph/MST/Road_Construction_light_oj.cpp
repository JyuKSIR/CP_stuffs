#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

struct DSU{

    vector<int> par,sz;
    int c;

    DSU(int n) : par(n,0),sz(n,1){
        c = n;
        for(int i=0; i<n; i++) par[i] = i;
    }

    int find(int i){
        if(i == par[i]) return i;
        return par[i] = find(par[i]);
    }

    bool same(int i,int j){
        return find(i) == find(j);
    }

    int count(){
        return c;
    }

    void join(int i, int j){
        i = find(i);
        j = find(j);
        if(i != j){
            c--;
            if(sz[i] < sz[j]) swap(i,j);
            par[j] = i;
            sz[i] += sz[j];
        }
    }
};

void solve(){
    
    int n; cin >> n;

    vector<array<int,3>> g;

    unordered_map<string,int> um;
    int id = 0;

    for(int i=0; i<n; i++){
        string u,v;
        int w;
        cin >> u >> v >> w;
        if(um.find(u) == um.end()) {
            um[u] = id; id++;
        }
        if(um.find(v) == um.end()) {
            um[v] = id; id++;
        }
        g.push_back({w,um[u],um[v]});
    }

    sort(g.begin(),g.end());

    int cost = 0;

    DSU d((int)um.size());

    for(auto [w,u,v] : g){
        if(d.same(u,v)) continue;
        cost += w;
        d.join(u,v);
    }

    if(d.count() > 1){
        cout << "Impossible\n";
        return;
    }
    cout << cost << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t,i = 1; cin >> t;

    while(t--){
        cout << "Case " << i << ": ";
        solve();
        i++;
    }

  return 0;
}
