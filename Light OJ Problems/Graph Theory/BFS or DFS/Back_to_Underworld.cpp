#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifdef LOCAL
#include "debugging_jinish.h"
#else
#define dbg(...) 1
#endif
 
template <typename num_t>
using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define ld long double

const int mxn = 2e4+5;

void solve(){

    vector<int> g[mxn]{};
    int vis[mxn]{},col[mxn]{};

    int n; cin >> n;

    for(int i=0; i<n; i++){
        int u,v; cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // vamp = 1;
    // lykans = 2;

    auto bfs = [&](int src) -> int {
        queue<int> q;
        int va = 0, ly = 0;
        q.push(src);
        vis[src] = 1;
        col[src] = 1;
        va++;
        while(!q.empty()){
            int p = q.front();
            q.pop();
            for(auto c : g[p]){
                if(!vis[c]){
                    q.push(c);
                    vis[c] = 1;
                    if(col[p] == 1){
                        col[c] = 2;
                        ly++;
                    }
                    else{
                        col[c] = 1;
                        va++;
                    }
                }
            }
        }
        return max(ly,va);
    };
    
    ll ans = 0;

    for(int i = 0; i < mxn; i++){
        if(!vis[i] && !g[i].empty()){
            ans += bfs(i);
        }
    }

    cout << ans << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;

    for(int i=1; i<=t; i++){
        cout << "Case " << i << ": "; solve();
    }

  return 0;
}
