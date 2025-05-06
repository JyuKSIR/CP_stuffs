#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

void solve(){

    int n,m; cin >> n >> m;

    const int inf = 1e9+10;

    vector<array<int,2>> g[n];
    vector<int> dis(n,inf),vis(n,0);

    for(int i=0; i<m; i++){
        int u,v,w; cin >> u >> v >> w;
        u--,v--;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    auto dijkstra = [&](int s) -> void {
      
        priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> pq;

        pq.push({0,s});
        dis[s] = 0;

        while(!pq.empty()){
            auto [w,p] = pq.top();
            pq.pop();

            if(vis[p]) continue;
            vis[p] = 1;

            for(auto [c,w] : g[p]){
                if(dis[p] + w < dis[c]){
                    dis[c] = dis[p] + w;
                    pq.push({dis[c],c});
                }
            }
        }
    };

    dijkstra(0);

    if(dis[n-1] == inf){
        cout << "Impossible\n";
        return;
    }

    cout << dis[n-1] << "\n";
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
