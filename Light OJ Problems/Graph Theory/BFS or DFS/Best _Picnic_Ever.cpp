#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
template <typename num_t>
using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define ld long double
#define dbg(a) cerr << __LINE__ << " no. line: " << #a << " = " << a << "\n"

void solve(){

   int k,n,m; cin >> k >> n >> m;

   vector<int> g[n+1];
   int vis[n+1]{}, go[n+1]{},l[k];

   for(int i=0; i<k; i++) cin >> l[i];
    
    for(int i=0; i<m; i++){
      int u,v; cin >> u >> v;
      g[u].push_back(v);
    }

    auto bfs = [&](int s) -> void{
      queue<int> q;
      q.push(s);
      vis[s] = 1;
      go[s]++;
      while(!q.empty()){
         int p = q.front();
         q.pop();
         for(auto c : g[p]){
            if(!vis[c]){
               vis[c] = 1;
               go[c]++;
               q.push(c);
            }
         } 
      }
    };

    for(int i=0; i<k; i++){
      memset(vis,0,sizeof(vis));
      bfs(l[i]);
    }
    
    int ans = 0;

    for(int i=1; i<=n; i++){
      if(go[i] == k) ans++;
    }

    cout << ans << "\n";

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t,i=1; cin >> t;

    while(t--){
       cout << "Case " << i << ": ";
       solve();
       i++;
    }

  return 0;
}
