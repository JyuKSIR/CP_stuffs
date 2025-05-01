#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define ld long double

void solve(){

    int n,m; cin >> n >> m;

    vector<int> g[2*m],gr[2*m],f;
    int vis[2*m]{},who[2*m];
    set<int> ans;

    for(int i=0; i<n; i++){
        char c,d; int a,b;
        cin >> c >> a >> d >> b;
        a--,b--;
        a*=2,b*=2;
        if(c == '-') a^=1;
        if(d == '-') b^=1;

        g[a^1].push_back(b);
        g[b^1].push_back(a);
        gr[b].push_back(a^1);
        gr[a].push_back(b^1);
    }

    function<void(int)> dfs1 = [&](int p){
        vis[p] = 1;
        for(auto c : g[p]){
            if(!vis[c]) dfs1(c);
        }
        f.push_back(p);
    };

    for(int i=0; i<2*m; i++){
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

    for(int i=2*m-1; ~i; i--){
        if(vis[f[i]]){
            dfs2(f[i],ct);
            ct++;
        }
    }

    for(int i=0; i<m; i++){
        if(who[2*i] == who[2*i+1]){
            cout << "No\n";
            return;
        }
        if(who[2*i] > who[2*i+1]){
            ans.insert(i+1);
        }
    }

    cout << "Yes\n" << ans.size() << " ";
    for(auto x : ans) cout << x << " ";
    cout << "\n";
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
