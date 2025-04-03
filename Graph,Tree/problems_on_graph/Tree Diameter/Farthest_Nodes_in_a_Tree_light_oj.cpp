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

void solve(){

    int n; 
    cin >> n;

    vector<int> g[n];
    int dis[n]{},vis[n]{};
    map<pair<int,int>,int> mp;

    for(int i=1; i<n; i++){
        int u,v,w; cin >> u >> v >> w;
        g[u].push_back(v);
        g[v].push_back(u);
        mp[{u,v}] = w;
        mp[{v,u}] = w;
    }
    
    function<void(int)> dfs = [&](int p){  // we will check the diameter in terms of weight
        vis[p] = 1;
        for(auto c : g[p]){
            if(!vis[c]){
                dis[c] = dis[p] + mp[{c,p}];
                dfs(c); 
            }
        }
    };

    dfs(0);

    int last = 0;
    int mxn = -1;

    for(int i=0; i<n; i++){
        if(dis[i]>mxn){
            mxn = dis[i];
            last = i;
        }
        dis[i] = 0;
    }

    memset(vis,0,sizeof(vis));
    mxn = -1;
    dfs(last);

    for(int i=0; i<n; i++){
        if(dis[i] > mxn){
            mxn = dis[i];
        }
    }

    cout << mxn << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, i=1; 
    cin >> t;

    while(t--){
       cout << "Case " << i << ": ";
       solve();
       i++;
    }

  return 0;
}
