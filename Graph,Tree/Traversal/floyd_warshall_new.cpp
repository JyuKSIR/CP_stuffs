#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

    ll n,m,q; cin >> n >> m >> q;

    const ll inf = 1e18+10;

    ll dis[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j) dis[i][j] = 0;
            else dis[i][j] = inf;
        }
    }

    for(int i=0; i<m; i++){
        ll u,v,w; cin >> u >> v >> w;
        u--,v--;
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = min(dis[v][u], w);
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dis[i][k] < inf and dis[k][j] < inf){
                    dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
    }

    while(q--){
        int x,y; cin >> x >> y;
        x--,y--;
        if(dis[x][y] == inf){
            cout << "-1\n";
        }
        else cout << dis[x][y] << "\n";
    }

  return 0;
}
//https://cses.fi/problemset/task/1672
