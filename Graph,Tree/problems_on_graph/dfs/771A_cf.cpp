#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

void solve(){

    ll n, m;
    cin >> n >> m;
    vector<ll> g[n];
    ll vis[n]{};
    ll ed,no;

    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    function<void(ll)> dfs = [&](ll p){
        vis[p] = 1;
        no++;
        for(auto c : g[p]){
            ed++;
            if(!vis[c]){
                dfs(c);
            }
        }

    };

    for (ll i = 0; i < n; i++) {
        if(!vis[i]){
            ed = no = 0;
            dfs(i);
            if(ed != (no*(no-1))){ //every component complete graph edge == node(node-1)/2 for (undirected) here counted twice so edge == node(node-1)
                cout << "NO\n";    // edge == node(node-1) (directed)
                return;
            }
        } 
    }
    cout << "YES\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  
       solve();

  return 0;
}
