#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,e; cin >> n >> e;

    vector<int> g[n], gr[n], scc, finishing;
    int vis[n]{};

    for(int i=0; i<e; i++){
        int u,v; cin >> u >> v;
        u--; v--;
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
        finishing.push_back(p);
    };

    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs1(i);
        }
    }

    memset(vis, 0, sizeof(vis));

    function<void(int)> dfs2 = [&](int p){
        vis[p] = 1;
        for(auto c : gr[p]){
            if(!vis[c]){
                dfs2(c);
            }
        }
        scc.push_back(p);
    };
    
    vector<int> ans;
    for(int i= n - 1; ~i; i--){
        if(!vis[finishing[i]]){
            dfs2(finishing[i]);
            if(scc.size() == n){
                cout << "YES\n";
                return 0;
            }
            else{
                ans.push_back(finishing[i]);
            }
            scc.clear();
        }
    }
    
    cout << "NO\n" << ans[1]+1 << " " << ans[0]+1;

  return 0;
}
