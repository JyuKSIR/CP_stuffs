#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

void solve(){

    ll n,m; cin >> n >> m;

    const ll inf = 1e18+10;

    vector<array<ll,2>> g[n];
    vector<ll> d1(n,inf),d2(n,inf);

    for(int i=0; i<m; i++){
        ll u,v,w; cin >> u >> v >> w;
        u--,v--;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }


    auto dijkstra = [&](ll s) -> void{

        priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<>> pq;

        d1[s] = 0;
        pq.push({0,s});

        while(!pq.empty()){

            auto [wt,p] = pq.top();
            pq.pop();

            for(auto [c, w] : g[p]){
                if(wt + w < d1[c]){  // wt is distance to p and d[p] is shortest distance to p
                    d2[c] = d1[c];   // we use wt not d[p]
                    d1[c] = wt + w;
                    pq.push({d1[c], c});
                }
                else if(wt + w > d1[c] and wt + w < d2[c]){
                    d2[c] = wt + w;
                    pq.push({d2[c], c});
                }
            }
        }
    };

    dijkstra(0);

    cout << d2[n-1] << "\n";
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
