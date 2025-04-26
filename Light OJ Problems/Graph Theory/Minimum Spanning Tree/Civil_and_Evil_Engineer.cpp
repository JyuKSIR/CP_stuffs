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

    void join(int i, int j){
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

    int n; cin >> n;

    vector<array<int,3>> g;

    while(1){
        int u,v,w; cin >> u >> v >> w;
        if(u == 0 and v == 0 and w == 0) break;
        g.push_back({w,u,v});
    }

    sort(g.begin(),g.end());

    DSU d1(n+1);

    int cost1 = 0;

    for(auto e : g){
        int w = e[0], u = e[1], v = e[2];
        if(d1.same(u,v)) continue;
        cost1 += w;
        d1.join(u,v);
    }

    sort(g.rbegin(),g.rend());

    DSU d2(n+1);

    int cost2 = 0;

    for(auto e : g){
        int w = e[0], u = e[1], v = e[2];
        if(d2.same(u,v)) continue;
        cost2 += w;
        d2.join(u,v);
    }

    int cost = cost1 + cost2;

    if(cost & 1){
        cout << cost << "/2" << "\n";
        return;
    }
    cout << cost/2 << "\n";

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
