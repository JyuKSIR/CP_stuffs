// input
8 10
0 1
1 2
2 0
2 3
3 4
4 5
5 6
6 4
6 7
4 7
// output
DFS order finishing time: 
7 6 5 4 3 2 1 0 
Connected components: 
count : 4
0 2 1 
3 
4 6 5 
7


#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,e; cin >> n >> e;

    vector<int> g[n];
    vector<int> gr[n];
    vector<int> finishing;
    vector<vector<int>> scc;
    vector<int> cur_cc; 
    int vis[n]{};

    for(int i = 0; i < e; i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    function<void(int)> dfs = [&](int p){
        vis[p] = 1;
        for(auto c : g[p]){
            if(!vis[c]){
                dfs(c);
            }
        }
        finishing.push_back(p);
    };
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    memset(vis, 0, sizeof(vis));

    function<void(int)> dfs1 = [&](int p){
        vis[p] = 1;
        cur_cc.push_back(p);
        for(auto c : gr[p]){
            if(!vis[c]){
                dfs1(c);
            }
        }
    };

    for(int i = (int)finishing.size() - 1; i >= 0; i--){
        if(!vis[finishing[i]]){
            cur_cc.clear();
            dfs1(finishing[i]);
            scc.push_back(cur_cc);
        }
    }
    cout << "DFS order finishing time: \n";
    for(auto a : finishing) cout << a << " ";
    cout << "\nConnected components: ";
    cout << "\ncount : " << scc.size() << "\n";
    for(auto temp : scc){
        for(auto z : temp){
            cout << z << " ";
        }
        cout << "\n";
    }

  return 0;
}

//also can watch this code
// https://github.com/JyuKSIR/CP_stuffs/blob/main/Graph%2CTree/problems_on_graph/SCC/planets_and_kingdomCSES.cpp
