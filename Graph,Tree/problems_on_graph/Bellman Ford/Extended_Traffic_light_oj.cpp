#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

void solve(){

    ll n; cin >> n;
    ll ar[n], dis[n];
    vector<array<ll,3>> g;

    const ll inf = 1e18+10;

    for(int i=0; i<n; i++){
        cin >> ar[i];
    }

    for(int i=0; i<n; i++){
        dis[i] = inf;
    }

    ll m; cin >> m;

    for(int i=0; i<m; i++){
        ll u,v,w; cin >> u >> v;
        u--,v--;
        ll wt = ar[v] - ar[u];
        w = wt * wt * wt;
        g.push_back({u,v,w});
    }

    auto bell = [&](ll s) -> void {
        dis[s] = 0;
        for(int i=0; i<n-1; i++){
            for(auto [u,v,w] : g){
                if(dis[u] != inf and dis[u] + w < dis[v]){
                    dis[v] = dis[u] + w;
                }
            }
        }
    };

    bell(0);

    ll q; cin >> q;

    while(q--){
        ll x; cin >> x; x--;
        if(dis[x] < 3 or dis[x] == inf){
            cout << "?\n";
        }
        else cout << dis[x] << "\n";
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t,i = 1; cin >> t;

    while(t--){
        cout << "Case " << i << ":\n";
        solve();
        i++;
    }

  return 0;
}
