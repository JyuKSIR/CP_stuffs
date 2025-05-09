#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

void solve(){

    int n,m; cin >> n >> m;

    vector<int> g[n];
    int vis[n]{},who[n];

    ll cost[n];

    for(int i=0;  i<n; i++){
        cin >> cost[i];
    }

    for(int i=0; i<m; i++){
        int  u,v;  cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ll cos = 0,tot = 0;;

    function<void(int,int)> dfs1 = [&](int p,int r){
        vis[p] = 1;
        who[p] = r;
        cos = min(cos,cost[p]);
        for(auto c : g[p]){
            if(!vis[c]) dfs1(c,r);
        }
    };

    for(int i=0; i<n; i++){
        if(!vis[i]){
            cos = 1e9+10;
            dfs1(i,i);
            tot += cos;
        }
    }

    cout << tot << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  
       solve();

  return 0;
}
