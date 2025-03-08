// https://www.youtube.com/watch?v=zBbRgLpeZus&t=682s
// input
8 6
1 2
2 3
2 4
3 5
6 7
1 5
// output
1

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,e; cin >> n >> e;

    vector<int> g[n+1];
    int vis[n+1]{};

    for(int i = 0; i < e; i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    function<bool(int,int)> cycle = [&](int chi, int par){
        vis[chi] = 1;
        bool cycleExists = false;
        for(auto ver : g[chi]){
            if(vis[ver] && ver == par) continue;
            if(vis[ver]) return true;

            cycleExists |= cycle(ver,chi);
        }
        return cycleExists;
    };

    bool exists = false;
    for(int i = 1; i <= n; i++){
         if(vis[i]) continue;
         if(cycle(i,-1)){
            exists = true;
            break;
         }
    }
    cout << exists << "\n";


  return 0;
}
