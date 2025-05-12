#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

void solve(){

    int n,t; cin >> n >> t;

    vector<int> g[n+1];

    for(int i=1; i<n; i++){
        int a; cin >> a;
        g[i].push_back(i+a);
    }

    int vis[n+1]{};

    function<void(int)> dfs = [&](int p){
        vis[p] = 1;
        for(auto c : g[p]){
            if(!vis[c]) dfs(c);
        }
    };

    dfs(1);

    if(vis[t]) cout << "YES\n";
    else cout << "NO\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  
       solve();

  return 0;
}
