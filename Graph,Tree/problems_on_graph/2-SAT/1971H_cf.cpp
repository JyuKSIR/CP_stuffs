#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

void solve(){

    int n; cin >> n;
    vector<array<int,3>> v(n);

    vector<int> g[2*n],gr[2*n],f;
    int vis[2*n]{},who[2*n];

    for(int j=0; j<3; j++){
        for(int i=0; i<n; i++){
            cin >> v[i][j];
        }
    }

    for(auto [x,y,z] : v){
        // x v y v z = (x v y) ∧ (x v z) ∧ (y v z)
        vector<array<int,2>> e = {{x,y},{x,z},{y,z}};

        for(auto [a,b] : e){

            int na = abs(a) - 1;
            int nb = abs(b) - 1;

            na *= 2;
            nb *= 2;

            if(a < 0) na ^= 1;
            if(b < 0) nb ^= 1;

            g[na^1].push_back(nb);
            g[nb^1].push_back(na);
            gr[nb].push_back(na^1);
            gr[na].push_back(nb^1);

        }
    }

    function<void(int)> dfs1 = [&](int p){
        vis[p] = 1;
        for(auto c : g[p]){
            if(!vis[c]) dfs1(c);
        }
        f.push_back(p);
    };

    for(int i=0; i<2*n; i++){
        if(!vis[i]) dfs1(i);
    }

    function<void(int,int)> dfs2 = [&](int p,int r){
        vis[p] = 0;
        who[p] = r;
        for(auto c : gr[p]){
            if(vis[c]) dfs2(c,r);
        }
    };

    int ct = 0;

    for(int i = 2*n-1; ~i; --i){
        if(vis[f[i]]){
            dfs2(f[i],ct);
            ct++;
        }
    }

    for(int i=0; i<n; i++){
        if(who[2*i] == who[2*i+1]){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;

    while(t--){
       solve();
    }

  return 0;
}
