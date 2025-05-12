#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

void solve(){

    ll n,m; cin >> n >> m;

    vector<ll> g[n],com;
    int vis[n]{},ans[n];

    for(ll i =0; i<m; i++){
        ll k; cin >> k;
        vector<ll> in(k);
        for(int j=0; j<k; j++){
            cin >> in[j];
            in[j]--;
        }

        for(int j=0; j<k-1; j++){
            g[in[j]].push_back(in[j+1]);
            g[in[j+1]].push_back(in[j]);
        }
    }

    auto bfs = [&](ll s) -> void {
        queue<ll> q;
        q.push(s);
        vis[s] = 1;
        while(!q.empty()){
            ll p = q.front(); q.pop();
            com.push_back(p);
            for(auto c : g[p]){
                if(!vis[c]){
                    q.push(c);
                    vis[c] = 1;
                }
            }
        }
    };

    for(int i=0; i<n; i++){
        if(!vis[i]){
            com.clear();
            bfs(i);
            for(auto x : com) ans[x] = com.size();
        }
    }

    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  
       solve();

  return 0;
}
