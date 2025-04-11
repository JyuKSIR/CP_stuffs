#include<bits/stdc++.h>
using namespace std;

int main(){

    const int inf = 1e9 + 10;

    int n,m; cin >> n >> m;

    vector<pair<int,int>> g[n+1];
    int dis[n+1];

    for(int i=0; i<m; i++){
        int u,v; cin >> u >> v;
        if(u == v) continue;
        g[u].push_back({v,0});
        g[v].push_back({u,1});
    }

    auto zobfs = [&](int sr) -> int {
        deque<int> dq;
        dq.push_back(sr);
        dis[sr] = 0;
        while(!dq.empty()){
            int p = dq.front();
            dq.pop_front();
            for(auto [c,wt] : g[p]){
                if(dis[p] + wt < dis[c]){
                    dis[c] = dis[p] + wt;
                    if(wt == 1) dq.push_back(c);
                    else dq.push_front(c);
                }
            }
        }
        return dis[n] == inf ? -1 : dis[n];
    };

    memset(dis,inf,sizeof(dis));

    cout << zobfs(1) << "\n";

  return 0;
} 
// minimum cost to make a path where path doesn't exist
