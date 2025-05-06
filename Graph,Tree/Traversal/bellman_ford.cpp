#include<bits/stdc++.h>
using namespace std;

int main(){


    int n,m; cin >> n >> m;
    vector<array<int,3>> g;
    int dis[n];

    const int inf = 1e9+10;

    for(int i=0; i<n; i++){
        dis[i] = inf;
    }

    for(int i=0; i<m; i++){
        int u,v,w; cin >> u >> v >> w;
        u--,v--;
        g.push_back({u,v,w});
    }

    auto bell =[&](int p)-> bool{
        dis[p] = 0;
        for(int i=0; i<n-1; i++){
            for(auto [u,v,w] : g){
                if (dis[u] != inf && dis[u] + w < dis[v]) {
                    dis[v] = dis[u] + w;
                }
            }
        }

        for(auto [u,v,w] : g){
            if (dis[u] != inf && dis[u] + w < dis[v]) {
                return true;
            }
        }
        return false;
    };

    bool cycle = bell(0);

    if(cycle){
        cout << "negative weight cycle";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (dis[i] == inf) cout << "INF ";
        else cout << dis[i] << " ";
    }

  return 0;
}
