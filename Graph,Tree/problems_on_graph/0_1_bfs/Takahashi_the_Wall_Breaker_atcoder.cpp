// this problem is based on 0/1 bfs to find a path if we get '.' we dont need dash or front kick, for '#' he can front kick so
// for '#' he can go with 1 move and then 2 move thats why two time breaking 1st and 2nd wall

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    const int inf = 1e9+50;
    int n,m; cin >> n >> m;
    vector<vector<char>> g(n,vector<char>(m));
    vector<vector<int>> dis(n,vector<int>(m,inf));

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> g[i][j];
        }
    }

    int sx,sy,ex,ey; cin >> sx >> sy >> ex >> ey;
    sx--,sy--,ex--,ey--;

    auto val = [&](int a, int b) -> bool {
        if(a < 0 or a >= n or b < 0 or b >= m) return false;
        return true;
    };

    auto zobfs = [&](int sx,int sy, int ex, int ey) -> int {
        deque<pair<int,int>> dq;
        dq.push_back({sx,sy});
        dis[sx][sy] = 0;
        while(!dq.empty()){
            auto [px,py] = dq.front();
            if (px == ex and py == ey) {
                return dis[px][py];
            }
            dq.pop_front();
            for(int i=0; i<4; i++){  // for 0 weights
                int cx = px + dx[i],
                    cy = py + dy[i];
                if(val(cx,cy) and g[cx][cy] == '.' and dis[px][py] < dis[cx][cy] ){
                        dis[cx][cy] = dis[px][py];
                        dq.push_front({cx,cy});
                }
            }

            for(int i=0; i<4; i++){  // for 1 weights
                int cx = px + dx[i],
                    cy = py + dy[i];
                if(val(cx,cy) and g[cx][cy] == '#' and dis[px][py] + 1 < dis[cx][cy] ){
                    dis[cx][cy] = dis[px][py] + 1;
                    dq.push_back({cx,cy});
                }
                cx += dx[i],  // for 1 weights 2nd move
                cy += dy[i];
                if(val(cx,cy) and g[cx][cy] == '#' and dis[px][py] + 1 < dis[cx][cy] ){
                    dis[cx][cy] = dis[px][py] + 1;
                    dq.push_back({cx,cy});
                }
            }
        }
        return dis[ex][ey];
    };

    cout << zobfs(sx,sy,ex,ey);

  return 0;
}
