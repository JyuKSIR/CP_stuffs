#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m; cin >> n >> m;
    
    vector<int> g[n],o;
    int par[n]{}, d[n]{}, vis[n]{};

    for(int i=0; i<m; i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    function<void(int)> bfs =[&](int v){
        queue<int> q;
        q.push(v);
        vis[v] = 1;
        while(!q.empty()){
            int p = q.front();
            o.push_back(p);
            q.pop();
            for(auto c : g[p]){
                if(!vis[c]){
                    q.push(c);
                    vis[c] = 1;
                    par[c] = p;
                    d[c] = d[p] + 1;
                }
            }
        }
    };

    bfs(0);

    cout << "BFS order: ";
    for(auto x : o) cout << x << ' ';

  return 0;
}
