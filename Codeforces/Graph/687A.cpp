#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

void solve(){

    ll n,m; cin >> n >> m;

    vector<ll> g[n],sa,sb;
    int vis[n]{},col[n];

    int bipart = 1;

    for(ll i=0; i<m; i++){
        ll u,v; cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    function<void(ll,ll)> dfs = [&](ll p, ll x){
        vis[p] = 1;
        col[p] = x;
        for(auto c : g[p]){
            if(!vis[c]){
                dfs(c,x^1);
            }
            else{
                if(col[c] == x){
                    bipart = 0;
                }
            }
        }
    };

    for(ll i=0; i<n; i++){
        if(!vis[i]){
            dfs(i,0);
        }
    }

    if(!bipart){
        cout << "-1";
        return;
    }
    for(ll i=0; i<n; i++){
        if(col[i] == 1) sa.push_back(i+1);
        else sb.push_back(i+1);
    }

    cout << sa.size() << "\n";
    for(auto x : sa) cout << x << " ";

    cout << "\n";

    cout << sb.size() << "\n";
    for(auto x : sb) cout << x << " ";

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  
       solve();

  return 0;
}
