#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

void solve(){

    int n,m; cin >> n >> m;

    vector<vector<int>> g(n,vector<int>(m));
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<int>> dis(n,vector<int>(m,0));

    int dx[8] = {-1, -1, -1,  0, 0, 1, 1, 1};
    int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

    int mx = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> g[i][j];
            mx = max(mx,g[i][j]);
        }
    }
    auto val = [&](int x, int y) -> bool {
        if(x >=0 and x < n and y >= 0 and y < m and !vis[x][y]) return true;
        return false;
    };

    auto bfs = [&]() -> int {
        int ans = 0;
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(g[i][j] == mx){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            auto [a,b] = q.front();
            q.pop();

            for(int i=0; i<4; i++){
                int ca = a + dx[i];
                int cb = b + dy[i];
                if(val(ca,cb)){
                    vis[ca][cb] = 1;
                    dis[ca][cb] = dis[a][b] + 1;
                    q.push({ca,cb});
                    ans = max(ans,dis[ca][cb]);
                }
            }
        }
        return ans;
    };

    cout << bfs() << "\n";

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
// https://vjudge.net/problem/CodeChef-SNSOCIAL
