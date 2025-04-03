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

    int n,k = 0; cin >> n;

    vector<vector<char>> g(n,vector<char>(n));
    vector<vector<int>> vis(n,vector<int>(n,0));

    pair<int,int> pos[26];

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> g[i][j];
            if(g[i][j] >= 'A' and g[i][j] <= 'Z'){
                pos[g[i][j] - 'A'] = {i,j};
                k++;
            }
        }
    }
    auto val = [&](int x,int y, char c) -> bool{
        if(x >= 0 and x < n and y >= 0 and y < n and !vis[x][y] and g[x][y] != '#'){ //the alphabhet we are finding without this all are obstabcles like '#' and 'A','C','D' to Z
            if(g[x][y] == '.' or g[x][y] == c ){
                return true;
            }
        }
        return false;
    };

    auto bfs = [&](int sx,int sy,int ex, int ey,char c) -> int {
        vector<vector<int>> dis(n,vector<int>(n,0));
        queue<pair<int,int>> q;
        q.push({sx,sy});
        vis[sx][sy] = 1;

        while(!q.empty()){
            auto [a,b] = q.front();
            q.pop();
            if(ex == a and ey == b) return dis[a][b];
            for(int i=0; i<4; i++){
                int ca = a + dx[i];
                int cb = b + dy[i];
                if(val(ca,cb,c)){
                    vis[ca][cb] = 1;
                    dis[ca][cb] = dis[a][b] + 1;
                    q.push({ca,cb});
                }
            }

        }
        return -1;
    };

    int total_dis = 0;
    
    for(int i=0; i<k-1; i++){
        vis = vector<vector<int>>(n,vector<int>(n,0));
        char c1 = 'A' + i + 1; // it had to find the next alphabhet
        auto [fx,fy] = pos[i];
        auto [lx,ly] = pos[i+1];
        int la = bfs(fx,fy,lx,ly,c1);
        if(la == -1){
            cout << "Impossible\n";
            return;
        }
        total_dis += la;
    }

    cout << total_dis << "\n";

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
