// longest path in the tree
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;

    vector<int> g[n];
    int vis[n]{}, d[n]{};

    for(int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    function<void(int,int)> dfs = [&](int s,int p){    // dfs with the depth or order
        vis[s] = 1;
        for(auto c : g[s]){
            if(c != p && !vis[c]){
                d[c] = d[s]+1;
                dfs(c,s);
            }
        }
    };

    dfs(0,-1);   // run dfs from any node 
    int mxn = -1;
    int last;
    for(int i=0; i<n; i++){   // store the deepest node in last
        if(d[i]>mxn){    // search the node of largest depth
            mxn = d[i];
            last = i;
        }
        d[i] = 0;
    }
    memset(vis,0,sizeof(vis));

    dfs(last,-1);  // run dfs from thr last 
    mxn = -1;
    for(int i=0; i<n; i++){  // search the value of largest depth after running dfs for the node stored in last
        if(d[i]>mxn){
            mxn = d[i];   // now the value of the largest depth will be the diameter of the tree
        }
    }

    cout << mxn << "\n";

  return 0;
}
