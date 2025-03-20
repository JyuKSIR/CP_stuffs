#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,q; cin >> n >> q;

    vector<int> t[n];
    int d[n]{},anc[n][19]{};

    for(int i=1; i<n; i++){
        int x; cin >> x;
        x--;
        t[x].push_back(i);
    }
     
    function<void(int,int)> dfs = [&](int s,int p){
        anc[s][0] = p;
        for(int i=1; i<19; i++){
            if(anc[s][i-1] == -1){
                anc[s][i] = -1;
            }
            else anc[s][i] = anc[ anc[s][i-1] ][i-1];
        }
        for(auto c : t[s]){
            if(c != p){
                d[c] = d[s] + 1;
                dfs(c,s);
            }
        }
    };

    function<int(int,int)> kth = [&](int u,int k){
        for(int i=18; ~i; i--){
            if((k >> i) & 1) u = anc[u][i];
            if(u == -1) break;
        }
        return u;
    };

    function<int(int,int)> lca = [&](int u,int v){
        if(d[u] > d[v]) swap(u,v);

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
    dfs(0,-1);
    while(q--){
        int u,v; cin >> u >> v;
        u--; v--;
        cout << lca(u,v)+1 << "\n";
    }

  return 0;
}
