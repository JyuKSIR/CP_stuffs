#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m; cin >> n >> m;

    vector<int> g[2*m],gr[2*m],f;
    int vis[2*m]{},who[2*m];
    char ans[2*m];

    for(int i=0; i<n; i++){
        char c,d; int a,b;
        cin >> c >> a >> d >> b;
        a--,b--;
        a*=2;
        b*=2;
        if(c == '-') a^=1;   
        if(d == '-') b^=1;
        // x should be in even index -> 0,2,4,6....
        // !x should be in odd index -> 1,3,5,7....
        g[a^1].push_back(b);  // !a -> b
        g[b^1].push_back(a);  // !b -> a
        gr[b].push_back(a^1); // b -> !a 
        gr[a].push_back(b^1); // a -> !b
    }

    function<void(int)> dfs1 = [&](int p){
        vis[p] = 1;
        for(auto c : g[p]){
            if(!vis[c]){
                dfs1(c);
            }
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

    int ct = 0;  // no. of scc's

    for(int i = 2*m-1; ~i; i--){
        if(vis[f[i]]){
            dfs2(f[i],ct);
            ct++;
        }
    }

    for(int i=0; i<m; i++){
        if(who[2*i] == who[2*i+1]){  // if x and !x is in the same scc then it's not possible to assign truth values
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        ans[i] = (who[2*i] > who[2*i+1]) ? '+' : '-';  // if the id of x (even -> 2*i) is more then the id of !x (odd -> 2*i+1) then assign true or else assign false 
    }

    for(int i=0; i<m; i++) cout << ans[i] << " ";

  return 0;
}

// https://cses.fi/problemset/task/1684/
