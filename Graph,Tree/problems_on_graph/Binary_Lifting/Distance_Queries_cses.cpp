#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,q; cin >> n >> q;

    vector<int> t[n];
    int d[n]{},anc[n][19]{};

    for(int i=1; i<n; i++){
        int a,b; cin >> a >> b;
        a--,b--;
        t[a].push_back(b);
        t[b].push_back(a);
    }

    function<void(int,int)> dfs = [&](int s,int p){
        anc[s][0] = p;
        for(int i=1; i<19; i++){
            if(anc[s][i-1] == -1){
                anc[s][i] = -1;
            }
            else anc[s][i] = anc[anc[s][i-1]][i-1];
        }
        for(auto c : t[s]){
            if(c != p){
                d[c] = d[s]+1;
                dfs(c,s);
            }
        }
    };

    function<int(int,int)> kth = [&](int u,int k){
        for(int i=18; ~i; i--){
            if((k>>i)&1) u = anc[u][i];
            if(u == -1) break;
        }
        return u;
    };

    function<int(int,int)> lca = [&](int u,int v){

        if(d[u]>d[v]) swap(u,v);
        int diff = d[v]-d[u];
        v = kth(v,diff);

        if(u == v) return u;

        for(int i=18; ~i; i--){
            if(anc[u][i] != anc[v][i]){
                u = anc[u][i];
                v = anc[v][i];
            }
        }
        return anc[u][0];
    };

    function<int(int,int,int)> dist = [&](int u,int v, int z){ //distance(u,v) = depth(u) + depth(v) - 2 * depth(lca(u,v))
        return d[u] + d[v] - 2*d[z];
    };

    dfs(0,-1);

    while(q--){
        int u,v; cin >> u >> v;
        u--,v--;
        cout << dist(u,v,lca(u,v)) << "\n";
    }

  return 0;
}
