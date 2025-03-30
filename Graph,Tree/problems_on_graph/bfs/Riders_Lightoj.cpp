// so the plan will be simply run a bfs from every rider and mantain a 2d array of step or every rider there will be one or 
// multiple indices which will be equal to rider count also maintain a distance array to know the distance of every rider in every indices
// then just check which indices have the same count as the rider count found the minimum

// thanks juni for helping me out

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

void solve(){

    int n,m; cin >> n >> m;

    vector<pair<int, int>> riders;
    vector<vector<char>> tab(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dis(n, vector<int>(m, 0));
    vector<vector<int>> go(n, vector<int>(m, 0));

    int dx[8] = {1,1,2,2,-1,-1,-2,-2};
    int dy[8] = {2,-2,1,-1,2,-2,1,-1};

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> tab[i][j];
            if(tab[i][j] != '.'){
                riders.push_back({i,j});
            }
        }
    }
    auto val = [&](int x, int y) -> bool {
        if(x < 0 or x >= n or y < 0 or y >= m or vis[x][y]){
            return false;
        }
        return true;
    };

    auto bfs = [&](int sx, int sy,int k) -> void {
        vector<vector<int>> loc(n, vector<int>(m, 0));
        queue<pair<int,int>> q;
        q.push({sx,sy});
        vis[sx][sy] = 1;
        go[sx][sy]++;

        while(!q.empty()){
            auto p = q.front();
            int a = p.first;
            int b = p.second;
            q.pop();
            for(int i=0; i<8; i++){
                int cha = a + dx[i];
                int chb = b + dy[i];

                if(val(cha,chb)){
                    vis[cha][chb] = 1;
                    loc[cha][chb] = loc[a][b] + 1;
                    dis[cha][chb] += ceil(1.0*loc[cha][chb]/k);
                    go[cha][chb]++;
                    q.push({cha,chb});
                }
            }
        }
    };

    for(auto [x,y] : riders){
        vis = vector<vector<int>>(n, vector<int>(m, 0));
        int k = tab[x][y] - '0';
        bfs(x,y,k);
    }

    int c = riders.size();
    int ans = 1e9;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(go[i][j] == c){
                ans = min(ans,dis[i][j]);
            }
        }
    }

    if(ans == 1e9){
        cout << "-1\n";
    }
    else cout << ans << "\n";
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
