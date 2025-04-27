#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m,s,e; cin >> n >> m >> s >> e;
    s--,e--;

    const int inf = 1e9+10;

    vector<array<int,2>> g[n];   // node,weight
    vector<int> vis(n,0),dis(n,inf);


    for(int i=0; i<m; i++){
        int u,v,w; cin >> u >> v >> w;
        u--,v--;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    auto dijkstra = [&](int s,int e) -> int{

        set<array<int,2>> st;  // weight,node
        st.insert({0,s});  
        dis[s] = 0;

        while(!st.empty()){

            auto [w,p] = *st.begin();
            st.erase(st.begin());
            if(vis[p]) continue;
            vis[p] = 1;
            for(auto [c,w] : g[p]){
                if(dis[p] + w < dis[c]){
                    dis[c] = dis[p] + w;
                    st.insert({dis[c],c});
                }
            }
        }
        return dis[e];
    };

    cout << dijkstra(s,e);

  return 0;
}
