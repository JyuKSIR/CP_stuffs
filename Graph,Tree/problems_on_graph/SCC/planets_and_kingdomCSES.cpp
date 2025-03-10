#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m; cin >> n >> m;

    vector<int> g[n],gr[n],f,scc; // scc is the id or the first number of the strongly connected component
    int who[n], vis[n]{};  // who will be the which node in which scc(id)

    for(int i=0; i<m; i++){
        int u,v; cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    function<void(int)> dfs1 = [&](int p){
        vis[p] = 1;
        for(auto c : g[p]){
            if(!vis[c]){
                dfs1(c);
            }
        }
        f.push_back(p);
    };

    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs1(i);
        }
    }
    
    function<void(int,int)> dfs2 = [&](int p, int r){
        vis[p] = 0;
        who[p] = r;
        for(auto c : gr[p]){
            if(vis[c]){
                dfs2(c,r);
            }
        }
    };
    
    int ct = 0;
    for(int i=n-1; ~i; i--){
        if(vis[f[i]]){
            dfs2(f[i],f[i]);
            scc.push_back(f[i]);
        }
    }

    cout << scc.size() << "\n";
    map<int,int> mp;
    for(int i=0; i<scc.size(); i++){
        mp[scc[i]] = i;
    }

    for(int i=0; i<n; i++){
        cout << mp[who[i]]+1 << " ";
    }

  return 0;
}
