// dfs on a 2D grid
// always use vector

// here it asks me in wich nodes prince can visit just run a dfs from the @ part and count the 1's in visited array those are the nodes prince will visit

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

    int n,m; cin >> n >> m;

    vector<vector<char>> g(m, vector<char>(n));  // m*n row = m, colomn = n;
    vector<vector<int>> vis(m, vector<int>(n,0));

    int a,b;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> g[i][j];
            if(g[i][j] == '@'){
                a = i; b = j;
            }
        }
    }

    auto val = [&](int x,int y) -> bool {

        if(x < 0 or x >= m or y < 0 or y >= n or g[x][y] == '#' or vis[x][y]){
            return false; // out of bound and visted
        }
        return true;
    };

    function<void(int,int)> dfs = [&](int x, int y){

        vis[x][y] = 1;

        if(val(x-1,y)){  //up
            dfs(x-1,y);
        }
        if(val(x+1,y)){  //down
            dfs(x+1,y);
        }
        if(val(x,y-1)){  //left
            dfs(x,y-1);
        }
        if(val(x,y+1)){  //right
            dfs(x,y+1);
        }

    };

    dfs(a,b);

    int ct = 0;

    for(auto v : vis){
        ct += count(v.begin(),v.end(), 1);
    }

    cout << ct << "\n";
    
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;

    for(int i=1; i<=t; i++){
       cout << "Case " << i << ": "; 
       solve();
    }

  return 0;
}
