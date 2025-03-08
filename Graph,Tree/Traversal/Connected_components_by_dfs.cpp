// https://www.youtube.com/watch?v=zBbRgLpeZus&t=682s
// input
8 5
1 2
2 3
2 4
3 5
6 7
// output
DFS order: 
1 2 3 5 4 6 7 8 
Connected components: 
count : 3
1 2 3 5 4 
6 7 
8 
// https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,e; cin >> n >> e;

    vector<int> g[n+1];
    int vis[n+1]{};
    vector<vector<int>> cc;
    vector<int> cur_cc;
    vector<int> dfso;

    for(int i = 0; i < e; i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    function<void(int)> dfs = [&](int x){
        dfso.push_back(x);
        cur_cc.push_back(x);
        vis[x] = 1;
        for(auto y : g[x]){
            if(!vis[y]){
                dfs(y);
            }
        }
    };
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cur_cc.clear();
            dfs(i);
            cc.push_back(cur_cc);
        }
    }
    cout << "DFS order: \n";
    for(auto a : dfso) cout << a << " ";
    cout << "\nConnected components: ";
    cout << "\ncount : " << cc.size() << "\n";
    for(auto temp : cc){
        for(auto z : temp){
            cout << z << " ";
        }
        cout << "\n";
    }

  return 0;
}
