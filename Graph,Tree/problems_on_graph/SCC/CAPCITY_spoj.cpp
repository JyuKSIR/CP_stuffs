#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m; cin >> n >> m;

    vector<int> g[n],gr[n],scc,f;
    int who[n],vis[n]{};
    map<int,int> mp;

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

    for(int i=n-1; ~i; i--){
        if(vis[f[i]]){
            dfs2(f[i],f[i]);
            scc.push_back(f[i]);
        }
    }

    for(int i=0; i<n; i++){
        mp[who[i]]++;
    }
    int need = 0,check = 0;
    for(auto p : mp){
        if(p.second> check){
            check = p.second;
            need = p.first;
        }
    }

    vector<int> ans;
    for(int i=0; i<n; i++){
        if(who[i] == need){
            ans.push_back(i+1);
        }
    }

    sort(ans.begin(),ans.end());

    cout << ans.size() << "\n";
    for(auto x : ans) cout << x << " ";

  return 0;
}

// had to print the values of largest scc and it's size
