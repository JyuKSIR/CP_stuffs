#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

int main(){

    ll n; cin >> n;

    vector<ll> g[n], gr[n], scc, f;
    ll who[n], vis[n]{}, cost[n];
    ll mn, ct, need = 0, ways = 1;

    for(ll i=0; i<n; i++){
        cin >> cost[i];
    }

    ll m; cin >> m;

    for(ll i=0; i<m; i++){
        ll u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    function<void(ll)> dfs1 = [&](ll p){
        vis[p] = 1;
        for(auto c : g[p]){
            if(!vis[c]){
                dfs1(c);
            }
        }
        f.push_back(p);
    };

    for(ll i=0; i<n; i++){
        if(!vis[i]){
            dfs1(i);
        }
    }

    function<void(ll, ll)> dfs2 = [&](ll p, ll r){
        vis[p] = 0;
        who[p] = r;

        if(cost[p] == mn) ct++; // if cost and min are same it means there are one more way with same min cost

        if(mn > cost[p]){   // if found new min the count again from 1
            ct = 1;
            mn = cost[p];
        }

        for(auto c : gr[p]){
            if(vis[c]){
                dfs2(c,r);
            }
        }
    };

    for(ll i = n-1; i >= 0; i--){
        if(vis[f[i]]){

            mn = LLONG_MAX;
            ct = 0;
            dfs2(f[i], f[i]);
            need += mn;

            if(ct){
                ways = (ways * ct) % mod;
            }
        }
    }

    cout << need << " " << ways;

    return 0;
}
